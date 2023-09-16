//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod=1000000007;
    long long solve(int n,vector<int>&dp){
        if(n==0)return 1;
        
        if(dp[n]!=-1)return dp[n];
        long long a=0;
        if(n>=1){
             a= solve(n-1,dp);
        }
        long long b=0;
        if(n>=2){
            b= solve(n-2,dp);
        }
        long long c=0;
        if(n>=3){
            c=solve(n-3,dp);
        }
        return dp[n]=(a%mod+b%mod+c%mod)%mod;
    }
    long long countWays(int n)
    {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends