class Solution {
public:
vector<vector<string>> ans;
bool isPalin(string &k,int left, int right){
    while(left<right){
        if(k[left++]!=k[right--]) return false;
    }
    return  true;
}
void func(int start,int end, string s, vector<string> &vec){
    if(start==s.size()){
        ans.push_back(vec);
        return;
    }
    if(end==s.size()) return;

    if(isPalin(s,start,end)){
        vec.push_back(s.substr(start,end-start+1));
        func(end+1,end+1,s,vec);
        vec.pop_back();
    }
    func(start,end+1,s,vec);
}
    vector<vector<string>> partition(string s) {
        
        vector<string> vec;
        func(0,0,s,vec);
        return ans;
    }
};