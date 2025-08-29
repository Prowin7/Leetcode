class Solution {
public:
    string compressedString(string word) {
        int n = word.length();

        int j = 1;
        int cnt = 1;
        string ans = "";
        char ch = word[0];
        while (j < n) {
            if (word[j] == ch && cnt < 9) {
                cnt++;
            }

            else {
                ans.push_back(cnt + '0');
                ans.push_back(ch);
                ch = word[j];
                cnt = 1;
            }
            j++;
        }
        ans.push_back(cnt+'0');
        ans.push_back(ch);
        return ans;
    }
};
