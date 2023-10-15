//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
   void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>>& grid){
       visited[row][col] = 1;
       queue<pair<int,int>> q;
       q.push({row, col});
       int n = grid.size();
       int m = grid[0].size();
       
       while(!q.empty()){
           int row = q.front().first;
           int col = q.front().second;
           q.pop();
           
           //traverse the neighbours 
           for(int drow = -1; drow<=1; drow++){
               for(int dcol = -1; dcol<=1; dcol++){
                   int nrow = row+drow;
                   int ncol = col+dcol;
                   if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                       visited[nrow][ncol] = 1;
                       q.push({nrow, ncol});
                   }
               }
           }
       }
   }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends