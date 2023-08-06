//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int ans=0;
        int countneg=0;
        for(int i=1 ; i<str.size() ; i++)
        {
            if(str[i]=='-' ||str[i]=='+' )
            return -1;
        }
       for(int i=0 ; i<str.size() ;i++)
       {
    
              if(isalpha(str[i])) return -1;
              if(str[i]=='-'||str[i]=='+') continue;
            
               int value=str[i]-'0';
               ans=ans+(value * pow(10 , str.size()-i-1));


       }
       if(str[0]=='-') return -1*ans;
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends