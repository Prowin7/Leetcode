class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r=image.size();
        int c=image[0].size();
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;  
        
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty()){
            int cr=q.front().first;
            int cc=q.front().second;
            q.pop();
            for(auto d:dir){
                int row=cr+d.first;
                int col=cc+d.second;
                if(row<0||col<0||row==r||col==c||image[row][col]!=originalColor)
                    continue;
                image[row][col]=color;
                q.push({row,col});
            }
        }
        return image;
    }
};