class Solution {
    vector<int > path;
   bool dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;
        path[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
               if(dfs(it,vis,adj)==true) return true;
               }
            else if(path[it]) return true;
            
        }
        path[node]=0;
        return false;

    }

public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(num);
        for(int i=0;i<pre.size();i++){
            int a=pre[i][0];
            int b=pre[i][1];
            adj[b].push_back(a);
        }
        vector<int> vis(num,0);
        path=vector<int>(num,0);
        for(int i=0;i<num;i++){
            if(!vis[i]){
               if(dfs(i,vis,adj)) return false;
               
            }
        }
        return true;
    }
};