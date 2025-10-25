class Solution {
public:
    int minCost(string colors, vector<int>& need) {
        int n=colors.size();
        int i=0;
        int ans=0;
        while(i<n){
            int j=i;
            int groupSum=0;
            int groupMax=0;
            while(j<n && colors[j]==colors[i]){
                groupSum+=need[j];
                groupMax = max(groupMax,need[j]);
                j++;
            }
            ans+=(groupSum-groupMax);
            i=j;
        }
        return ans;
    }
};