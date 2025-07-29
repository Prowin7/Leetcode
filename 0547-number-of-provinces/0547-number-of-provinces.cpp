class Solution {
    void dfs(int node,vector<int> &vis,vector<vector<int>> &adj){
        vis[node]=1;
        for(auto neighbor:adj[node]){
            if(!vis[neighbor]){
                dfs(neighbor,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (isConnected[i][j] == 1 && i != j)
                adj[i].push_back(j);
            }
        }
        int cnt=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};