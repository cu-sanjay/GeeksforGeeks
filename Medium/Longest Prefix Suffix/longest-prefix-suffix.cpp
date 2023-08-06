//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:
    int lps(string s) 
    {
        int k=0;
        int l=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[k]==s[i])
            {
                k++;
                continue;
            }
            i=l;
            l++;
            k=0;
        }
        return k;
    }
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends