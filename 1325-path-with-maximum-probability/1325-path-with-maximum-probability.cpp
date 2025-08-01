class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            double  wt = succProb[i];
            adj[a].push_back({b,wt});
            adj[b].push_back({a,wt});
        }
        vector<double> dist(n,0.0);
        dist[start]=1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        while(!pq.empty()){
            int node=pq.top().second;
            double dis=pq.top().first;
            if(node==end) return dis;
            pq.pop();
            for(auto it:adj[node]){
                int next=it.first;
                double wt=it.second;
                if(dis*wt>dist[next]){
                    dist[next]=dis*wt;
                    pq.push({dist[next],next});
                }
                
            }
        }
        return 0.0;
    }
};