class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> rightMax(n,0);
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,nums[i]);
            rightMax[i]=maxi;
        }
        set<int> s;
        s.insert(nums[0]);
        for(int i=1;i<n;i++){
            s.insert(nums[i]);
            auto it = s.find(nums[i]);
            if(it!=s.begin() && nums[i]!=rightMax[i]){
                if((*--it)<nums[i] && nums[i]<rightMax[i]) return true;
            }

        }
        return false;
    }
};