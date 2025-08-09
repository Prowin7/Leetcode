class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int cnt=0;
        const int MOD=1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            int a=it[0];
            int b=it[1];
            int time=it[2];
            adj[a].push_back({b,time});
            adj[b].push_back({a,time});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0}); //{time,node}
        
        vector<long long> dist(n,1e18);
        vector<int> ways(n,0);
        ways[0]=1;
        dist[0]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            long long time=pq.top().first;
            
            pq.pop();
            if(time>dist[node]) continue;
            for(auto it:adj[node]){
                int next=it.first;
                long long t=it.second;

                if(t+time<dist[next]){
                    
                    dist[next]=t+time;
                    ways[next]=ways[node];
                    pq.push({dist[next],next});
                }
                else if(t+time==dist[next]){
                    ways[next]=(ways[next]+ways[node])%MOD;
                }
            }
        }
        
        return ways[n-1];

    }
};