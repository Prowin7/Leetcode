class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r=image.size();
        int c=image[0].size();
        queue<pair<int,int>> q;
        int org=image[sr][sc];
        if(image[sr][sc]==color) return image;
        q.push({sr,sc});
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
                int cr=q.front().first;
                int cc=q.front().second;
                q.pop();
                image[cr][cc]=color;
                for(auto it:dir){
                    int row=cr+it.first;
                    int col=cc+it.second;
                    if(row<0||col<0||row==r||col==c||image[row][col]!=org)
                    continue;
                    q.push({row,col});
                }
            
        }
        return image;
    }
};