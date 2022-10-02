#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        //KAHN'S ALGO
        unordered_map<int,int> in;
       for(int i=0;i<V;i++){
           in[i]=0;
       }
        for(int i=0;i<V;i++){
          for(int u:adj[i]){
              in[u]++;
          }
      }
       queue<int> q;
       for(auto it : in){
           if(it.second == 0){
               q.push(it.first);
           }
       }
       
       vector<int> ans;
       
       while(!q.empty()){
           int t = q.front();
           ans.push_back(t);
           q.pop();
           for(auto it: adj[t]){
               in[it]--;
               if(in[it]==0){
                   q.push(it);
               }
           }
       }
       if(ans.size()!=V){
           return 1;
       }
       else{
           return 0;
       }
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
