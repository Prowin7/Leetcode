// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            for(auto it : edges){
                int a=it[0];
                int b=it[1];
                int wt=it[2];
                if(dist[a]+wt<dist[b]&&dist[a]!=1e8){
                    dist[b]=dist[a]+wt;
                }
            }
        }
        
        // Nth iteration to check negative cycle
        
        for(auto it :edges){
            int a=it[0];
            int b=it[1];
            int wt=it[2];
            if(dist[a]+wt<dist[b] && dist[a]!=1e8){
                return {-1};
            }
        }
        return dist;
    }
};
