class Solution {
public:
    vector<int> addToArrayForm(vector<int>& digits, int k) {
        int n = digits.size();
        int carry = k;
        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        
        // FIX: split carry into digits instead of inserting whole number
        while (carry > 0) {
            digits.insert(digits.begin(), carry % 10);
            carry /= 10;
        }
        
        return digits;
    }
};
