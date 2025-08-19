class Solution {
    vector<vector<int>> ans;
    void dfs(int node,vector<int> &path,vector<vector<int>>&graph){
        path.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(path);
        }
        else{
            for(int neigh:graph[node]){
                dfs(neigh,path,graph);
            }
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(0,path,graph);
        return ans;
    }
};