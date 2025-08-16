class DisjointSet{
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
    bool unionRank(int u,int v){
        int par_u=find(u);
        int par_v=find(v);
        if(par_u==par_v) return false;
        if(rank[par_u]<rank[par_v]){
            parent[par_u]=par_v;
        }
        else if(rank[par_v]<rank[par_u]){
            parent[par_v]=par_u;
        }
        else{
            parent[par_v]=par_u;
            rank[par_u]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n+1);
        for(auto it:edges){
            if(!ds.unionRank(it[0],it[1])) return it;
        }
        return {};
    }
};