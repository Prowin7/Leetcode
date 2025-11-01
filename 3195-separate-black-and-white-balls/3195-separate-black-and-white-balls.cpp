class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0;
        long long zeroPos = 0;  // next position where '0' should go
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                steps += (i - zeroPos);
                zeroPos++;
            }
        }
        return steps;
    }
};
