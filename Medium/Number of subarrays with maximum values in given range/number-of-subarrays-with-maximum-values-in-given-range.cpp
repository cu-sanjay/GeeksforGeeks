//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int arr[], int n, int L, int R)
    {
        // Complete the function
        
        //ask a simple question:
        //this elem is maxi in what all subarrays
        ///figure out the left boundary
        //figure out the right boundary
        //ans = (l1+1)*(r1+1);
        
        vector<int>leftbound(n, 0);
        vector<int> rightbound(n, n-1);
        
        stack<int>st;
        int i = n-1;
        while(i >= 0){
            
            if(st.empty()){
                st.push(i);
            }
            else{
                //stack is not empty
                if(arr[i] > arr[st.top()]){
                
                    while(!st.empty() && arr[i] > arr[st.top()]){
                        leftbound[st.top()] = i+1;
                        st.pop();
                    }
                    
                    st.push(i);
                    
                }
                else{
                    st.push(i);
                }
                
            }
            
            i--;
        }
        
        //empty the stack
        while(!st.empty()){
            st.pop();
        }
        
        i = 0;
        
        while(i < n){
            
            if(st.empty()){
                st.push(i);
            }
            else{
                
                //rightbound such that >= 
                while(!st.empty() && arr[i] >= arr[st.top()]){
                    rightbound[st.top()] = i-1;
                    st.pop();
                }
                st.push(i);
                
            }
            
            i++;
        }
        
        //empty the stack
        while(!st.empty()){
            st.pop();
        }
        
        // cout<<"the left bound "<<endl;
        // for(auto it: leftbound){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        // cout<<"right bounds "<<endl;
        // for(auto it: rightbound){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        
        //formula
        
        long long int ans = 0;
        for(int i= 0; i<n; i++){
            if(arr[i] >= L && arr[i] <= R){
                
                int lefty = leftbound[i];
                int righty = rightbound[i];
                int l1 = i - lefty;
                int r1 = righty-i;
                
                ans += (long(l1+1) * long(r1+1));
                
                
                
            }
        }
        
        
        return ans;
        
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends