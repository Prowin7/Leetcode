class Solution {
    int maxLen;
    int ind;
    void expand(int left,int right,string &s){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            if(right-left+1>maxLen){
                ind=left;
                maxLen=right-left+1;

            }
            left--;
            right++;
        }
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        maxLen=0;
        ind=0;
        for(int i=0;i<n;i++){
            expand(i,i,s);  //odd length
            expand(i,i+1,s); // even length
        }
        return s.substr(ind,maxLen);
    }
};