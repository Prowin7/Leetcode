class Solution {
    int lower_bound(vector<int>&arr,int target){
        int lo=0,hi=arr.size()-1;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]<target){
                lo=mid+1;
            }
            else
                hi=mid;
        }
        if(arr[lo]>=target) return lo;
        if(arr[hi]>=target) return hi;
        return arr.size();
    }
    int upper_bound(vector<int>&arr,int target){
        int lo=0,hi=arr.size()-1;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]<=target){
                lo=mid+1;
            }
            else
                hi=mid;
        }
        if(arr[lo]>target) return lo;
        if(arr[hi]>target) return hi;
        return arr.size();
    }
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first=lower_bound(arr,target);
        int last=upper_bound(arr,target)-1;
        if(first>=0&&last>=0) return last-first+1;
        return 0;
    }
};
