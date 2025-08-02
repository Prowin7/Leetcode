class Solution {
    int cnt;
    void expand(int left,int right,string &s){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            cnt++;
            left--;
            right++;
        }
    }
public:
    int countSubstrings(string s) {
        cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            expand(i,i,s); // odd length
            expand(i,i+1,s); // even length
        }
        return cnt;
    }
};