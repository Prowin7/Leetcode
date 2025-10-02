class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int top = 0;
        int left = 0;
        int right = n - 1;
        int bottom = n - 1;
        int k=1;
        while(left<=right && top<=bottom){
           
            for(int i=left;i<=right;i++){
                ans[top][i]=k;
                k++;
            }
            top++;
           
            for(int i=top;i<=bottom;i++){
               ans[i][right]=k;
                k++;
            }
           right--;
            
            if(top<=bottom){
                
                for(int i=right;i>=left;i--){
                   ans[bottom][i]=k;
                    k++;
                }
                bottom--;
              
            }
            
            
            if(left<=right){
                
                for(int i=bottom;i>=top;i--){
                    ans[i][left]=k;
                    k++;
                }
                left++;
                
            }
            
        }
        return ans;
    }
};