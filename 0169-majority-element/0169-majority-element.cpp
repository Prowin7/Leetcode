class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int m;
        if(n%2==1) m=n/2+1;
        else m=n/2;
        int el=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]==el) cnt++;
            if(nums[i]!=el && cnt<2){
                el=nums[i];
            }
            if(cnt>=m) return el;
            
        }
        return nums[n-1];
        
    }
};