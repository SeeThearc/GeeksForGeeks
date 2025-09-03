class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        queue<int>q;
        vector<vector<int>>adjLis(V);
        vector<int>inDegree(V,0);
        for(int i=0;i<edges.size();i++){
            adjLis[edges[i][0]].push_back(edges[i][1]);
            inDegree[edges[i][1]]++;
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it:adjLis[temp]){
                inDegree[it]--;
            }
            for(int i=0;i<V;i++){
                if(!vis[i] && inDegree[i]==0){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return ans;
    }
};