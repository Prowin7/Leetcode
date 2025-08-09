class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,1e9);
        dist[src]=0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            int start=it[0];
            int end=it[1];
            int cost=it[2];
            adj[start].push_back({end,cost});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}}); //{stops,{node,cost}}
        while(!q.empty()){
            int node=q.front().second.first;
            int stops=q.front().first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                int next=it.first;
                int c=it.second;
                if(c+cost<dist[next]){
                    dist[next]=c+cost;
                    q.push({stops+1,{next,dist[next]}});
                }
            }
        }
        if(dist[dst]!=1e9) return dist[dst];
        return -1;
    }
};