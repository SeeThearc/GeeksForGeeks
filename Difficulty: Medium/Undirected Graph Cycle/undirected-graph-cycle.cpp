class Solution {
  public:
    bool detect(int src,vector<vector<int>>&adj ,vector<int>&vis){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjan:adj[node]){
                if(!vis[adjan]){
                    vis[adjan]=1;
                    q.push({adjan,node});
                }
                else if(parent!=adjan){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>vis(V,0);
        vector<vector<int>>adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                if(detect(i,adj,vis))return true;
            }
        }
        return false;
    }
};