class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p=0,q=0;
        int i=1;
        bool f1=false,f2=false,f3=false;
        while(i<n && nums[i-1]<nums[i] ){
            p=i;
            i++;
            f1=true;
        }
        while( i<n && nums[i-1]>nums[i]  ){
            
            q=i;
            i++;
            f2=true;
        }
        while(i<n && nums[i-1]<nums[i]  && i>=q){
            f3=true;
            i++;
        }
        return (f1&&f2&&f3&&i==n);

    }
};