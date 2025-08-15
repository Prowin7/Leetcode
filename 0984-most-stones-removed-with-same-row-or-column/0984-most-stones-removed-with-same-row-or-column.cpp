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
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node]);
    }   
    void unionRank(int u,int v){
        int ulp_u=find(u);
        int ulp_v=find(v);
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
       int row=0;
       int col=0;
       for(auto it:stones){
            row=max(row,it[0]);
            col=max(col,it[1]);
       }
       DisjointSet ds(row+col+1);
       unordered_map<int,int> mp;
       for(auto it:stones){
            int r=it[0];
            int c=it[1]+row+1;
            ds.unionRank(r,c);
            mp[r]=1;
            mp[c]=1;
       }
       int cnt=0;
       for(auto it:mp){
            if(ds.find(it.first)==it.first) cnt++;
       }
       
        return n-cnt;
        
    }
};