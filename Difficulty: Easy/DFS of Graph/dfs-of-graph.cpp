//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
        void dfs(int start,int visited[],vector<int>&ls,vector<vector<int>>adj){
            visited[start]=1;
            ls.push_back(start);
            for(auto it:adj[start]){
                if(!visited[it]){
                    dfs(it,visited,ls,adj);
                }
            }
        }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int visited[adj.size()]={0};
        vector<int>dfsls;
        int src=0;
        dfs(src,visited,dfsls,adj);
        return dfsls;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends