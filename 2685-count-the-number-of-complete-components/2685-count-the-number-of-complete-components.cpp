class Solution {
    void dfs(int node, vector<vector<int>>& adj,vector<int>&vis,int &nodes, int &edges){
        vis[node]=1;
        nodes++;
        edges+=adj[node].size();
        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                dfs(neigh,adj,vis,nodes,edges);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int nodes =0;
                int edgesc =0;
                dfs(i,adj,vis,nodes,edgesc);
                edgesc/=2;
                if(edgesc== (nodes*(nodes-1))/2){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};