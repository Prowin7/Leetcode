class Solution {
public:
    int substrCount(string &s, int k) {
        int n = s.size();
        if (k > n) return 0;

        unordered_map<char, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;  // include current character

            // maintain window size = k
            if (right - left + 1 > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }

            // when window size == k, check condition
            if (right - left + 1 == k && freq.size() == k - 1)
                count++;
        }

        return count;
    }
};
