class Solution {
    vector<vector<int>> ans;
    int n;
    vector<int> visited;
    void backtrack(int node,vector<vector<int>>&graph,vector<int> &path){
        path.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        visited[node] = true;
        for(auto neigh:graph[node]){
            if(!visited[neigh]){
                backtrack(neigh,graph,path);
            }
        }
        visited[node]=false;
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        visited = vector<int>(n, false);
        vector<int> path;
        backtrack(0, graph,path);
        return ans;
    }
};