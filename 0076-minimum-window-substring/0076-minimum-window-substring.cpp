class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        for(auto it:t) need[it]++;
        int i = 0;
        int j = 0;
        int start = 0;
        int len = s.size()+1;
        int remaining = t.size();
        while(j<s.size()){
            char c = s[j];
            if(need[c]>0){
                remaining--;
            }
            need[c]--;
            while(remaining==0){
                if(j-i+1<len){
                    len = j-i+1;
                    start = i;
                }
                char c = s[i];
                need[c]++;
                if(need[c]>0){
                    remaining++;
                }
                i++;
            }
            j++;
        }
        return len==s.size()+1 ? "": s.substr(start,len);
    }
};