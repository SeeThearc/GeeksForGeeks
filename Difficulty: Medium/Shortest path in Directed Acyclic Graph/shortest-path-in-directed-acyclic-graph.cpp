// User function Template for C++
class Solution {
  public:
    void dfs(vector<vector<pair<int,int>>>&adjLis,stack<int>&st,int node,vector<int>&vis){
        vis[node]=1;
        for(auto it:adjLis[node]){
            int i = it.first;
            if(!vis[i]){
                dfs(adjLis,st,i,vis);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int>dist(V,1e9);
        vector<vector<pair<int,int>>>adjLis(V);
        for(int i=0;i<E;i++){
            adjLis[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        stack<int>st;
        vector<int>vis(V,0);
        dfs(adjLis,st,0,vis);
        dist[0]=0;
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            for(auto it:adjLis[node]){
                int v = it.first;
                int w = it.second;
                if(dist[node]+w<dist[v]){
                    dist[v] = dist[node]+w;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==1e9)dist[i]=-1;
        }
        return dist;
    }
};
