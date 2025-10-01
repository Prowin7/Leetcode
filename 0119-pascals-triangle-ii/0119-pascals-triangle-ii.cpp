class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            vector<int> sub(i+1,1);
            for(int j=1;j<i;j++){
                sub[j]=ans[j-1]+ans[j];
            }
            ans=sub;
        }
        return ans;
    }
};