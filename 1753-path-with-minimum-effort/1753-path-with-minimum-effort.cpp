class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}}); // effort, {row,col}
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
        while(!pq.empty()){
            int cr=pq.top().second.first;
            int cc=pq.top().second.second;
            int effort=pq.top().first;
            if (cr == r - 1 && cc == c - 1) return effort;
            pq.pop();
            for(auto d:dir){
                int row=cr+d.first;
                int col=cc+d.second;
                if(row<0||col<0||row==r||col==c) continue;
                int newEffort=max(effort,abs(heights[row][col]-heights[cr][cc]));
                if(newEffort<dist[row][col]){
                    dist[row][col]=newEffort;
                    pq.push({newEffort,{row,col}});
                }

            }
        }
        return 0;
    }
};