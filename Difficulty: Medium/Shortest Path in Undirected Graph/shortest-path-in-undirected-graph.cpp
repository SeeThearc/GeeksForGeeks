class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int>dist(n,1e9);
        queue<int>q;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto it:adj[temp]){
                if(dist[temp]+1<dist[it]){
                    dist[it] = 1 + dist[temp];
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};