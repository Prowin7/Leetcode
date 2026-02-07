class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int del = 0;
        int b_cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                b_cnt++;

            }
            else {
                if(b_cnt>0){
                    del++;
                    b_cnt--;
                }
            }
        }
        return del;
    }
};