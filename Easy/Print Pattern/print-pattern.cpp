//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> v;
    void seq(int &n, vector<int>& v, int x){
        v.push_back(n);
        n -= 5;
        if(n<=0)return;
        if(n>0)seq(n,v,x);
    }
    void rseq(int &n, vector<int>& v, int x){
        v.push_back(n);
        n += 5;
        if(n<=x)rseq(n,v,x);
        return;
    }
    vector<int> pattern(int N){
        if(N<=0)return {N};
        int x = N;
        seq(N,v,x);
        rseq(N,v,x);
        return v;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends