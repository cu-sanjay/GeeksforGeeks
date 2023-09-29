//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs( int row , int col ,vector<vector<int>> &grid , vector<vector<int>> &vis , int *delrow , int *delcol ){
        
          // first mark visited 
        vis[row][col] =  1 ;
        
         int n = grid.size();
         int  m  = grid[0].size();
         
          //  check for direction (top , right , bottom , left) 
         for( int i  = 0 ; i < 4 ; i++){
             
             int newrow = row + delrow[i];
             int newcol = col + delcol[i];
             
             // check all bounday case 
             
        if( newrow >=0 && newrow < n && newcol >= 0 && newcol < m  && !vis[newrow][newcol] && grid[newrow][newcol] == 1){
            
               // check  connected to any 1  or or set of 1
               
            dfs( newrow , newcol , grid , vis , delrow , delcol);
        }
         }
      
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
       
         int n = grid.size();
         int  m  = grid[0].size();
      
       //  create the array to traverse in four direction
        int delrow[] = {-1 , 0 , 1 , 0};  // top right buttom left 
        int delcol[] = { 0 , 1 , 0, -1 }; 
        
        // visited vector to keep the track 
        
        vector<vector<int>> vis( n , vector<int>(m,0)); 
        
        // first column and last column  
        
         for(int i = 0 ; i < m ; i++){
             
             if( !vis[0][i] && grid[0][i] == 1){
                
                dfs(0 , i  , grid , vis , delrow , delcol);
             }
             
             if(!vis[n-1][i] && grid[n-1][i] == 1){
                 dfs( n-1 , i , grid , vis , delrow , delcol);
             }
         }
         
         // first row and last row
         
         for( int j  = 0 ; j  < n  ; j++){
             
             if( !vis[j][0] && grid[j][0] == 1){
                 dfs(j , 0 , grid , vis , delrow , delcol);
             }
             
             if(!vis[j][m-1] && grid[j][m-1] == 1){
                 dfs(j , m-1 , grid , vis , delrow , delcol);
             }
         }
         
         
         // now we can say that we have mark all (true) set of 1 which connected with boundary
         
         // Run loop and check  if any unvisited  1 or a set of 1 is present and count the 1 .
         
          int cnt = 0 ; 
          
          for(int i = 0 ; i < n ; i++){
              
              for(int j = 0 ; j < m ; j++){
                  
                  if(!vis[i][j] && grid[i][j] == 1){
                      cnt++;
                  }
              }
          }
          
          return cnt ;
         
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