class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    void unionSize(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        DisjointSet ds(r*c);
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        // dsu of 1's
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    int node=i*c+j;
                    for(auto d:dir){
                        int row=i+d.first;
                        int col=j+d.second;
                        if(row>=0 && col>=0 && row<r && col<c && grid[row][col]==1){
                            int neighbor=row*c+col;
                            ds.unionSize(node,neighbor);
                        }
                    }
                }
            }
        }

        // try all 0's
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    unordered_set<int> uniqueParents;
                    int cap=1;
                    for(auto d:dir){
                        int row=i+d.first;
                        int col=j+d.second;
                        if(row>=0 && col>=0 && row<r && col<c && grid[row][col]==1){
                            int p=ds.find(row*c+col);
                            if(!uniqueParents.count(p)){
                                cap+=ds.size[p];
                                uniqueParents.insert(p);
                            }
                        }
                    }
                    ans=max(ans,cap);   
                }
            }
        }
        for(int i=0;i<r*c;i++){
            if(ds.find(i)==i) ans=max(ans,ds.size[i]);
        }
        if(ans==0) return 1;
        return ans;
    }
};