//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int n = str1.length();
        if (n <= 2)
        {
            return false;
        }
        bool left = true, right = true;
        for (int i=0; i<n-2; i++)
        {
            if (str1[i] != str2[i + 2])
            {
                left = false;
                break;
            }
        }
        for (int i=0; i<n-2; i++)
        {
            if (str1[i + 2] != str2[i])
            {
                right = false;
                break;
            }
        }
        if (left or right)
        {
            return true;
        }
        return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends