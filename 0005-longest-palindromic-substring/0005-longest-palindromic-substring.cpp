class Solution {
    vector<vector<int>> dp;
    // bool solve(int i,int j,string &s){
    //     if(i>j) return 1;
    //     if(i==j) return 1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==s[j]){
    //         return dp[i][j]=solve(i+1,j-1,s);
    //     }
        
    //     return dp[i][j]=false;
        
    // }
    bool solve(int left,int right,string &s){
        while(left<right){
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=INT_MIN;
        int ind=0;
        dp=vector<vector<int>>(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s)){
                    if((j-i+1)>maxLen){
                        maxLen=j-i+1;
                        ind=i;
                    }
                }
            }
        }
        return s.substr(ind,maxLen);
    }
};