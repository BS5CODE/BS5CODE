//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node, vector<vector<int>> &adj, int visited[], int v )
  {
      visited[node] = 1;
      for(int i=0; i<v; i++)
      {
          if(visited[i] == 0 and adj[node][i] == 1)
          {
              dfs(i, adj, visited, v);
          }
      }
      
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int  numProvinces =0;
        int visited[V]={0};
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(i, adj, visited, V);
                 numProvinces++;
            }
        }
        return  numProvinces;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends