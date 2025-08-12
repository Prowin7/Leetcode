class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = arr[i] + prefix[i - 1];
        }

        // Remove wrong condition: if(prefix[n-1]==0 && n%4==0) return false;
        if (prefix[n - 1] % 3 != 0) return false;

        int bar = prefix[n - 1] / 3;
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == bar) {
                cnt++;
                sum = 0;
                // early stop if two parts found and still elements left
                if (cnt == 2 && i < n - 1) return true;
            }
        }
        return false;
    }
};
