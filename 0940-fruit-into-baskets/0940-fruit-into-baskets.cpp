class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;  // stores fruit type → count
        int i = 0, j = 0;
        int len = 0;

        while (j < n) {
            mp[fruits[j]]++;  // include fruit at j

            // If more than 2 fruit types, shrink the window from left
            while (mp.size() > 2) {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) 
                    mp.erase(fruits[i]);
                i++;
            }

            // Update maximum window length
            len = max(len, j - i + 1);
            j++;
        }

        return len;
    }
};
