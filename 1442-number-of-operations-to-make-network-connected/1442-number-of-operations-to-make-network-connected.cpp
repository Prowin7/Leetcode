class DisjointSet {
    vector<int> rank,parent;
    public: 
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
       
    }
     int find(int node){
            if(node==parent[node]) return node;
            return parent[node]=find(parent[node]);
        }
        
        void unionByRank(int u,int v){
            int ulp_u = find(u);
            int ulp_v = find(v);
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        DisjointSet ds(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.find(u)!=ds.find(v)){
                ds.unionByRank(u,v);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.find(i)==i) cnt++;
        }
        
        return cnt-1;
    }
};