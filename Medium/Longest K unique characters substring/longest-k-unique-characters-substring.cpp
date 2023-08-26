//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0,j=0;
        int n = s.size();
        int maxi = -1;
        unordered_map<char,int>map;
        
        while(j<n){
            // Step-1 :  Calculations
            map[s[j]]++;
            // Condition = map.size()
            if(map.size() < k){
                j++;
            }
            else if(map.size() == k){
                // Step-2 : Ans Calculation
                maxi = max(maxi,j-i+1);
                j++;
            }
            else if(map.size() > k){
                while(map.size() > k){
                    // Step-3 : Remove Calculations for i
                    map[s[i]]--;
                    if(map[s[i]]==0){
                        map.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends