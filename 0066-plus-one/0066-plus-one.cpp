class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n =digits.size();
        int carry = 1;
        for(int i=n-1;i>=0;i--){
            int sum = digits[i]+carry;
            digits[i] = sum%10;
            carry = sum/10;
        }
        if(carry){
            digits.insert(digits.begin(),carry);
        }
        while(digits.size()>1 && digits[0]==0){
            digits.erase(digits.begin());
        }
        return digits;
    }
};