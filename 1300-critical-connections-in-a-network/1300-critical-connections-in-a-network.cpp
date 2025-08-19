class Solution {
    vector<vector<int>> bridges;
    int timer=1;
    vector<int> tin;
    vector<int> low;
    void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        for(auto neigh:adj[node]){
            if(neigh==parent) continue;
            if(!vis[neigh]){
                dfs(neigh,node,vis,adj);
                low[node]=min(low[node],low[neigh]);
                if(low[neigh]>tin[node]){
                    bridges.push_back({neigh,node});
                }
            }
            else {
                low[node]=min(low[node],low[neigh]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        tin=vector<int>(n,0);
        low=vector<int>(n,0);
        dfs(0,-1,vis,adj);
        return bridges;
    }
};