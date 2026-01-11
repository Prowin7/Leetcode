class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st; // {startIndex, height}
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!st.empty() && st.top().second > heights[i]) {
                auto [idx, h] = st.top();
                st.pop();

                maxArea = max(maxArea, h * (i - idx));
                start = idx;  // extend current bar to the left
            }

            st.push({start, heights[i]});
        }

        // Process remaining bars
        int n = heights.size();
        while (!st.empty()) {
            auto [idx, h] = st.top();
            st.pop();
            maxArea = max(maxArea, h * (n - idx));
        }

        return maxArea;
    }
};
