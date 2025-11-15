// Intuition:
// Put all numbers in a set for O(1) lookups.
// A number starts a sequence only if (num - 1) doesn't exist.
// Then count how long the sequence (num, num+1, num+2...) goes.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int best = 0;

        for(int x : st) {
            if(!st.count(x - 1)) {           // x is the start of a sequence
                int y = x + 1;
                while(st.count(y)) y++;      // count forward
                best = max(best, y - x);     // length = (end - start)
            }
        }

        return best;
    }
};
