//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
     int countOccurence(int arr[], int n, int k) {
        // Your code here
        unordered_map<int, int>freq;
        
        for(int i = 0; i < n; i++)  
            ++freq[arr[i]];
            
        int t = n / k, res = 0;
        
        for(auto it : freq){
            if(it.second > t)   ++res;
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends