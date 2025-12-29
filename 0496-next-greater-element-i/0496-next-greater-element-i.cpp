class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> next;
        stack<int> st;

        for (int x : nums2) {
            while (!st.empty() && st.top() < x) {
                next[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        while (!st.empty()) {
            next[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(next[x]);
        }

        return ans;
    }
};
