//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool cycle(int source, vector<int> adj[], int vis[])
  {
      vis[source] = 1;
      // Store <source node, Source's Parent Node>
      queue<pair<int,int>> q;
      
      q.push({source,-1});
      
      // Traverse until queue is empty...
      while(!q.empty())
      {
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          // Going to all Adjacent Node...Of node.
          for(auto x: adj[node])
          {
              if(!vis[x]){
                  vis[x] = 1;
                  q.push({x,node});
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != x){
                  return true;
              }
          }
      }
      // Else there is no cycle...
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V]={0};
       for(int i=0; i<V; i++){
           if(!vis[i]){
               if(cycle(i,adj,vis)){
                   return true;
               }
           }
       }
       return false;
       }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends