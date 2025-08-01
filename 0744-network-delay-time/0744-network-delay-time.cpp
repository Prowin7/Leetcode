class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int a=times[i][0];
            int b=times[i][1];
            int wt=times[i][2];
            adj[a].push_back({b,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int next=it.first;
                int wt=it.second;
                if(dis+wt<dist[next]){
                    dist[next]=dis+wt;
                    pq.push({dist[next],next});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;  // Node not reachable
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;

    
    }
};