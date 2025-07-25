    class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int n=arr.size();
            int left=0;
            int right=n-1;
            while(left<=right){
                int mid=(left+right)/2;
                int missing=arr[mid]-(mid+1);
                if(missing < k){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
                
            }
            // for(int i=0;i<n;i++){
            //     if(arr[i]<=k){
            //         k++;
            //     }
            // }
            // return k;
            return left+k;
        }
    };