// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adjLis(V);
        int e = edges.size();
        for(int i=0;i<e;i++){
            adjLis[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int>dist(V,1e9);
        vector<int>vis(V,0);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({src,0});
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int node = t.first;
            int dis = t.second;
            for(auto it:adjLis[node]){
                int v = it.first;
                int w = it.second;
                if(dis+w<dist[v]){
                    dist[v]=dis+w;
                    pq.push({v,dist[v]});
                }
            }
        }
        return dist;
    }
};