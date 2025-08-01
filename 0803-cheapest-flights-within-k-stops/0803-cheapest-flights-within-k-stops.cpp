class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});// stops,node,cost
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int rate=it.second;
                if(cost+rate<dis[adjnode]&&stops<=k){
                    dis[adjnode]=cost+rate;
                    q.push({stops+1,{adjnode,cost+rate}});
                }

            }
        }
        if(dis[dst]==INT_MAX) return -1;
        else return dis[dst];
    }
};