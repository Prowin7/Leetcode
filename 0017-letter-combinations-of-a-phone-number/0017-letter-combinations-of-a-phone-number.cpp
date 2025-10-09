class Solution {
    vector<string> ans;
    void backtrack(int ind,string &digits,unordered_map<char,string> &keypad,string &cur){
        if(ind==digits.size()){
            ans.push_back(cur);
            return ;
        }
        char digit = digits[ind];
        string letters = keypad[digit];
        for(char ch:letters){
            cur.push_back(ch);
            backtrack(ind+1,digits,keypad,cur);
            cur.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0) return {};
        unordered_map<char,string> keypad;
        keypad['2']="abc";
        keypad['3']="def";
        keypad['4']="ghi";
        keypad['5']="jkl";
        keypad['6']="mno";
        keypad['7']="pqrs";
        keypad['8']="tuv";
        keypad['9']="wxyz";
        string cur;
        backtrack(0,digits,keypad,cur);
        return ans;
    }
};