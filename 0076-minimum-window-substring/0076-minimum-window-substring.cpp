class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<char,int> need;
        for(auto it:t){
            need[it]++;
        }

        int required=t.size();
        int i=0;
        int j=0;
        int start=0;
        int len=INT_MAX;
        while(j<n){
            if(need[s[j]]>0) 
                required--;
            need[s[j]]--;
            j++;
            while(required==0){
                if(j-i<len){
                    len=j-i;
                    start=i;
                }
                need[s[i]]++;
                if(need[s[i]]>0)
                    required++;
                i++;
            }
        }
         return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};