//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define ll long long
class Solution {
    public:
    int solve(string& s)
    {
        int mod=1e9+7;
	    int n=s.length();
	    vector<ll> dp(n+1,0);
	    unordered_map<ll,ll> mp;
	    
	    dp[0]=1;
	    for(int i=1;i<=s.length();i++)
	    {
	        char ch=s[i-1];
	        dp[i]=(2*dp[i-1])%mod;
	        if(mp.count(ch))
	        {
	            int ind=mp[ch];
	            dp[i]=((dp[i]-dp[ind-1])+mod)%mod;
	        }
	        mp[ch]=i;
	    }
	    
	    return dp[n];
    }
    
    string betterString(string str1, string str2) {
        int cnt1=solve(str1);
        int cnt2=solve(str2);
        
        if(cnt1>=cnt2)
        return str1;
        else 
        return str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends