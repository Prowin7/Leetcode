class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        // Two Pointer solution
        // int i=0;
        // while(i<n&&arr[i]<x) i++;
        // int left=i-1;
        // int right=i;
        // vector<int> ans;
        // while(left>=0&&right<n&&ans.size()<k){
        //         int a=abs(x-arr[left]);
        //         int b=abs(x-arr[right]);
        //         if(a<=b){
        //             ans.push_back(arr[left]);
        //             left--;
        //         }
        //         else{
        //             ans.push_back(arr[right]);
        //             right++;
        //         }
        // }
        // while(left>=0&&ans.size()<k){
        //     ans.push_back(arr[left]);
        //     left--;
        // }
        // while(right<n&&ans.size()<k){
        //     ans.push_back(arr[right]);
        //     right++;
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
        int left=0;
        int right=n-k;
        while(left<right){
            int mid=left+(right-left)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                left=mid+1;
            }
            else{
                right=mid;
            }

        }
        return vector<int> (arr.begin()+left,arr.begin()+left+k);
    }
};