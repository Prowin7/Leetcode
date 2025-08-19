class Solution {
int timer=1;
vector<int> tin;
vector<int> low;
vector<vector<int>> bridges;
void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj){
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto neigh:adj[node]){
        if(neigh==parent) continue;
        if(!vis[neigh]){
            dfs(neigh,node,vis,adj);
            low[node]=min(low[neigh],low[node]);
            if(low[neigh]>tin[node]){
                bridges.push_back({node,neigh});
            }
        }
        else{
            low[node]=min(low[node],low[neigh]);
        }
    }
}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            int a=it[0];
            int b=it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }    
        tin.resize(n,0);
        low.resize(n,0);
        vector<int> vis(n,0);
        dfs(0,-1,vis,adj); 
        return bridges; 
    }
};