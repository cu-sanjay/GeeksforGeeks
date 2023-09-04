//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void dfs(int i,int j,vector<vector<int>> &visit,vector<vector<char>> &mat){
        visit[i][j] = 1;
        
        int row[] = {-1,0,1,0};
        int col[] = {0,1,0,-1};
        
        for(int k=0;k<4;k++){
            int nr = i+row[k];
            int nc = j+col[k];
            
            if(nr < 0 || nr >= mat.size() || nc < 0 || nc >= mat[0].size())
                continue;
                
            if(!visit[nr][nc] && mat[nr][nc]=='O'){
                dfs(nr,nc,visit,mat);
                visit[nr][nc] = 1;
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> res=mat;
        vector<vector<int>> visit(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(mat[i][j]=='O' && !visit[i][j])
                        dfs(i,j,visit,mat);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j]==0){
                    res[i][j] = 'X';
                }
                else res[i][j] = 'O';
            }
        }   
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends