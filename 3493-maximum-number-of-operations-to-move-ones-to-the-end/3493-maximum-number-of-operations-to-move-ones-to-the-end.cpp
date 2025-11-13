class Solution {
public:
    int maxOperations(string s) {
        int cnt = 0, ones = 0;
        for(int i =0;i<s.size();i++){
            if(s[i] == '1')
                ones++;
            else{
                if (i > 0 && s[i - 1] == '1') cnt+=ones;
            }
        }
        return cnt;
    }
};
