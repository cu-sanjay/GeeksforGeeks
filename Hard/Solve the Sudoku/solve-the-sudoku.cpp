//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool safe(int grid[N][N],int i,int j, int num){
        for(int k=0;k<N;k++){
            if(grid[i][k]==num||grid[k][j]==num){
                return false;
            }
        }
        int sx=(i/3)*3;
        int sy=(j/3)*3;
        for(int x=sx;x<sx+3;x++){
            for(int y=sy;y<sy+3;y++){
                if(grid[x][y]==num){
                    return false;
                }
            }
        }
        return true;
    }
    bool soln(int grid[N][N],int i,int j){
        if(i==N){
            return true;
        }
        if(j==N){
            return soln(grid,i+1,0);
        }
        if(grid[i][j]!=0){
            return soln(grid,i,j+1);
        }
        for(int num=1;num<=N;num++){
            if(safe(grid,i,j,num)){
                grid[i][j]=num;
                bool issubsafe=soln(grid,i,j+1);
                if(issubsafe){
                    return true;
                }
            }
        }
        grid[i][j]=0;
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return soln(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends