//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        distance[0][0]=0;
        priority_queue<pair<int, pair<int,int>>, 
                        vector<pair<int, pair<int,int>>>, 
                        greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0,0}});
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int dist = pq.top().first;
            if(row==n-1 && col==m-1) return dist;
            pq.pop();
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int effort = max(abs(heights[nrow][ncol]-heights[row][col]), dist);
                    if(effort<distance[nrow][ncol]){
                        distance[nrow][ncol]=effort;
                        pq.push({effort, {nrow,ncol}});
                    }
                }
            }            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends