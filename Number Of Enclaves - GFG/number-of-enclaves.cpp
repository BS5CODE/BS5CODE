//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid,int n,int m, int detrow[], int detcol[]){
      vis[row][col] = 1;
      
      // check for top, right, bottom, left 
        for(int i = 0;i<4;i++) {
            int nrow = row + detrow[i];
            int ncol = col + detcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid,n,m, detrow, detcol); 
            }
        }
  }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int detrow[] = {-1,0,1,0};
        int detcol[] = {0,1,0,-1};
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        // Visited matrix to keep the recored of visited grid...
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        // Traverse the First and Last Row...
        for(int j=0; j<m; j++){
            
            // For first row...
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0,j,vis,grid,n,m,detrow,detcol);
            }
            
            // For last row...
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                dfs(n-1,j,vis,grid,n,m,detrow,detcol);
            }
        }
        
        // Traverse the First and Last Column...
        for(int i=0; i<n; i++){
            
            // For first col...
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i,0,vis,grid,n,m,detrow,detcol);
            }
            
            // For last col...
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i,m-1,vis,grid,n,m,detrow,detcol);
            }
        }
        
        for(int i = 0;i<n;i++) {
            for(int j= 0 ;j<m;j++) {
                if(!vis[i][j] && grid[i][j] == 1) 
                    count++; 
            }
        }
        
        return count; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends