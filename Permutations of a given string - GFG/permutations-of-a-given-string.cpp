//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void func(int index, string &S, vector<string> &ans){
        if(index == S.length()){
            ans.push_back(S);
            return;
        }
        for(int i = index; i < S.length(); i++){
            swap(S[index], S[i]);
            func(index+1, S, ans);
            swap(S[index], S[i]);
        }
    }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    func(0, S, ans);
		    sort(ans.begin(), ans.end());
		    ans.erase(unique(ans.begin(),ans.end()),ans.end());

		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends