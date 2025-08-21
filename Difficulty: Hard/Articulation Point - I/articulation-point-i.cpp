// User function Template for C++

class Solution {
    vector<int> vis;
    vector<int> tin;
    vector<int> low;
    vector<int> articulate;
    int timer=0;
    
    
    void dfs(int node,int parent,vector<int> adj[]){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                dfs(neigh,node,adj);
                child++;
                low[node]=min(low[node],low[neigh]);
                if(parent!=-1 && low[neigh]>=tin[node]){
                    articulate[node]=1;
                }
            } 
            else{
                low[node]=min(low[node],tin[neigh]);
            }
        }
        if(parent==-1 && child>1){
            articulate[node]=1;
        }
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
       vis.assign(V,0);
       low.assign(V,-1);
       tin.assign(V,-1);
       articulate.assign(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]){
               dfs(i,-1,adj);
           }
       }
       vector<int> ans;
       for(int i=0;i<V;i++){
           if(articulate[i]==1) ans.push_back(i);
       }
       if(ans.size()==0) return {-1};
       return ans;
    }
};