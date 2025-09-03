class Solution {
  public:
    void dfs(vector<vector<int>>&adjLis,int node,stack<int>&st,vector<int>&vis){
        vis[node]=1;
        for(auto it:adjLis[node]){
            if(!vis[it]){
                dfs(adjLis,it,st,vis);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adjLis(V);
        for(int i=0;i<edges.size();i++){
            adjLis[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adjLis,i,st,vis);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};