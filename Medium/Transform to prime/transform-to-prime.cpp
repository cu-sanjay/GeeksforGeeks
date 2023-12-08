//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int minNumber(int arr[],int N)
    {
        int ele = 0;
        int sum =0;
        for(int i =0;i<N;i++){
            sum+=arr[i];
        }
        if(sum==1){
            return 1;
        }
        
        while(1){
            int x = sum;
            int f=0;
            for(int i = 2;i<=sqrt(sum);i++){
                if(sum%i==0){
                    f=1;
                    break;
                }
            }
            if(f==0){
                return ele;
            }
            ele++;
            sum+=1;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends