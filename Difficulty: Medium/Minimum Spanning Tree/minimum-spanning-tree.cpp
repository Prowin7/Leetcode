class Solution {
  public:
    int spanningTree(int v, vector<vector<int>>& edges) {
        // code here
        // Prim's Algo
        vector<vector<pair<int,int>>> adj(v);
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            int wt=it[2];
            adj[a].push_back({b,wt});
            adj[b].push_back({a,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(v,0);
        pq.push({0,0}); // {weight,node}
        int sum=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                int nextNode=it.first;
                int nextWt=it.second;
                if(!vis[nextNode]){
                    pq.push({nextWt,nextNode});
                }
            }
            
        }
        return sum;
    }
};