class DisjointSet {
    
    vector<int> rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=find(u);
        int ulp_v=find(v);
        if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,pair<int,int>>> adj;
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj.push_back({wt,{u,v}});
        }
        sort(adj.begin(),adj.end());
        DisjointSet ds(V);
        int w=0;
        for(auto it:adj){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.find(u)!=ds.find(v)){
                w+=wt;
                ds.unionByRank(u,v);
            }
    
        }
        
        return w;
        
        
    }
};