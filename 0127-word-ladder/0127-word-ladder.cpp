class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());

        if(st.count(endWord)==0) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int len=q.front().second;
            q.pop();
            for(int i=0;i<word.size();i++){
                string temp=word;
                for(char c='a';c<='z';c++){
                    temp[i]=c;
                    if(temp==endWord) return len+1;
                    if(st.count(temp)){
                        q.push({temp,len+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};