class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> ans(1001,0);
        for(auto it:trips){
            ans[it[1]]+=it[0];
            ans[it[2]]-=it[0];
        }
        for(int i=0;i<1001;i++){
            capacity-=ans[i];
            if(capacity<0) return false;
            
        }
        return true;
    }
};