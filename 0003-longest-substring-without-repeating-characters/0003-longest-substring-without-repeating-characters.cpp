class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> need;
        int len=0;
        int i=0;
        int j=0;
        while(j<n){
            need[s[j]]++;
            
            while(need[s[j]]>1){
                need[s[i]]--;
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};