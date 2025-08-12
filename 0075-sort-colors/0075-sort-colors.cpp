class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        while(j<n){
            if(nums[j]!=2){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
        int k=0;
        int m=0;
        while(k<i){
            if(nums[k]!=1){
                swap(nums[k],nums[m]);
                m++;
            }
            k++;
        }
    }
};