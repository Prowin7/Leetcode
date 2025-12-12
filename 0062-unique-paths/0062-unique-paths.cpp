class Solution {
    int r,c;
    int func(int i,int j,vector<vector<int>>& ans){
        if(i>=r||j>=c) return 0;
        if(i==r-1&&j==c-1) return 1;
        int right = func(i,j+1,ans);
        int down = func(i+1,j,ans);
        return ans[i][j] = right+down;
    }
public:
    int uniquePaths(int m, int n) {
        r=m;
        c=n;
        vector<vector<int>> ans(m+1,vector<int>(n+1,0));
        return func(0,0,ans);
    }
};