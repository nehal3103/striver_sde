//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{src,0}}); 
        vector<int> distance(n, 1e9);
        distance[src]=0;
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops>K) continue; 
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                if(cost+edgeWeight < distance[adjNode] && stops<=K){
                    distance[adjNode] = cost+edgeWeight;
                    q.push({stops+1, {adjNode, cost+edgeWeight}});
                }
            }
        }
        if(distance[dst]==1e9) return -1;
        return distance[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends