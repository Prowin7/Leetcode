// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0;
        int j=0;
        while(j<n){
            if(arr[j]!=1){
                swap(arr[i],arr[j]);
                i++;
            }
            j++;
        }
    }
};