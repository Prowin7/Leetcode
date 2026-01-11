class Solution {
    int solve(vector<int>& heights){
        stack<pair<int,int>> st;
        int n = heights.size();
        int area=0;
        for(int i=0;i<n;i++){
            int start = i;
            while(!st.empty() && st.top().second>heights[i]){
                int h = st.top().second;
                int ind =  st.top().first;
                st.pop();
                area = max(area,h*(i-ind));
                start = ind;
            }
            st.push({start,heights[i]});
        }
        while(!st.empty()){
            int h = st.top().second;
            int ind =  st.top().first;
            st.pop();
            area = max(area,h*(n-ind));
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if(r==0) return 0;
        int c = matrix[0].size();
        vector<int> rect(c,0);
        int maxArea = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1'){
                    rect[j]++;
                }
                else {
                    rect[j]=0;
                }
            }
            maxArea = max(maxArea,solve(rect));
        }
        return maxArea;
    }
};