class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int res = 0; // result- no of jumps taken

        int cur = 0;

        int far =0 ; // fartherst index i can reach

        for(int i=0;i<n-1;i++){

            if(i+nums[i]>far) far = i+nums[i];

            if(i==cur){
                res++;
                cur = far; 
            }
            

        }
        return res;

    }
};