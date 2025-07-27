class Solution {
public:
    int findMin(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < arr[right]) {
                right = mid;
            } 
            else if (arr[mid] > arr[right]) {
                left = mid + 1;
            } 
            else {
                // arr[mid] == arr[right], we can safely ignore right
                right--;
            }
        }
        return arr[left];
    }
};
