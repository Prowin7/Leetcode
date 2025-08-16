class DisjointSet{
   public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    void unionSize(int u,int v){
        int par_u=find(u);
        int par_v=find(v);
        if(par_u == par_v) return; 
        if(size[par_u]<size[par_v]){
            parent[par_u]=par_v;
            size[par_v]+=size[par_u];
        }
        else{
            parent[par_v]=par_u;
            size[par_u]+=size[par_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        DisjointSet ds(n*m);
        // DSU FOR MAKING ISLANDS
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int node=i*m+j;
                    for(auto d:dir){
                        int row=i+d.first;
                        int col=j+d.second;
                        if(row>=0 && col>=0 && row<n&& col<m && grid[row][col]==1){
                            int neighbor=row*m+col;
                            ds.unionSize(node,neighbor);
                        }
                    }
                }
            }
        }
        // try flipping all zeroes
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    unordered_set<int> uniqueParent;
                    int cap=1;
                    for(auto d:dir){
                        int row=i+d.first;
                        int col=j+d.second;
                        if(row>=0&&col>=0 && row<n && col<m && grid[row][col]==1){
                            int p=ds.find(row*m+col);
                            if(!uniqueParent.count(p)){
                                cap+=ds.size[p];
                                uniqueParent.insert(p);
                            }
                        }
                    }
                    ans=max(ans,cap);
                }

            }
        }
        // edge cases
        for(int i=0;i<n*m;i++){
            if(ds.find(i)==i) ans=max(ans,ds.size[i]);
        }
        if (ans == 0) return 1;
        return ans;
    }
};