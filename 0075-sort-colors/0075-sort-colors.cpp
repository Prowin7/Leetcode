class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ind1=0;
        int ind2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                swap(nums[i],nums[ind1]);
                ind1++;
            }
        }
        int j =ind1;
        ind2=ind1;
        while(j<n){
            if(nums[j]==1){
                swap(nums[j],nums[ind2]);
                ind2++;
            }
            j++;
        }
        int k = ind2;
        int ind3=ind2;
        while(k<n){
            if(nums[k]==2){
                swap(nums[k], nums[ind3]);
                ind3++;
            }
            k++;
        }
      
    }
};