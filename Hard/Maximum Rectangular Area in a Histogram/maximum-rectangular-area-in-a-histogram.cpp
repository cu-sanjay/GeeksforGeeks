//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int>prev(n, -1);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prev[i]=st.top();
            }
            st.push(i);
        }
        
        vector<int>next(n, n);
        stack<int>stt;
        for(int i=n-1; i>=0; i--){
            while(!stt.empty() && arr[stt.top()]>=arr[i]){
                stt.pop();
            }
            if(!stt.empty()){
                next[i]=stt.top();
            }
            stt.push(i);
        }
        
        long long res=0;
        for(int i=0; i<n; i++){
            long long curr=arr[i];
            curr+=(i-prev[i]-1)*arr[i];
            curr+=(next[i]-i-1)*arr[i];
            res=max(curr, res);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends