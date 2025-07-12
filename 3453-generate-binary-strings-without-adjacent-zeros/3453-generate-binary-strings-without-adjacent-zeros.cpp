class Solution {
public:
void func(int n,string s,vector<string> &ans){
    if(s.length()==n){
        ans.push_back(s);
        return ;
    }
    if(s.empty() || s.back()=='1'){
        func(n,s+'0',ans);
    }
    func(n,s+'1',ans);
}
    vector<string> validStrings(int n) {
        // recursion method
        vector<string> ans;
        func(n,"",ans);
        return ans;
    }
};