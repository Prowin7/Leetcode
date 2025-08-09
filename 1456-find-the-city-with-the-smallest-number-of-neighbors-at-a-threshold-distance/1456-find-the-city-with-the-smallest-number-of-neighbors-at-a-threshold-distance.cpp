class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> mat(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) mat[i][j]=0;
            }
        }
        
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            int wt=it[2];
            mat[a][b]=wt;
            mat[b][a]=wt;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][via]!=1e8 && mat[via][j]!=1e8){
                        mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                    }
                }
            }
        }

        vector<int> cnt(n,0);
        int mini=n;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && mat[i][j]<=k){
                    count++;
                }
            }
            mini=min(mini,count);
            cnt[i]=count;
        }
        int number;
        for(int i=0;i<n;i++){
            if(cnt[i]==mini) number=i;
        }
        return number;

    }
};