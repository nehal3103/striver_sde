//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void func(vector<int> &arr, int N, vector<int> &answer, int index, int sum){
        if(index==N){
            answer.push_back(sum);
            return;
        }
        //pick
        func(arr, N, answer, index+1, sum + arr[index]);
        //no pick
        func(arr, N, answer, index+1, sum);

    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> answer;
        func(arr, N, answer, 0, 0);
        sort(answer.begin(), answer.end());
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends