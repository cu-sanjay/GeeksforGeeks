//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>outdeg(V+1,0);
        vector<int>radj[V+1];
        for(int i=0;i<V;i++){
            for(auto itr:adj[i]){
            radj[itr].push_back(i);    
            }
        }
        for(int i=0;i<V;i++){
              for(auto itr:radj[i]){
              outdeg[itr]++;   
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(outdeg[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int t=q.front();
            ans.push_back(t);
            for(int i=0;i<radj[t].size();i++){
                if(--outdeg[radj[t][i]]==0)q.push(radj[t][i]);
            }
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends