class Solution {
    vector<vector<int>> ans;
    
    void backtrack(int node, vector<vector<int>>& graph, vector<int>& path) {
        // If we reached the last node, save the current path
        if (node == graph.size() - 1) {
            ans.push_back(path);
            return;
        }

        // Explore all neighbors
        for (auto neigh : graph[node]) {
            path.push_back(neigh);
            backtrack(neigh, graph, path);
            path.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        path.push_back(0); // start from node 0
        backtrack(0, graph, path);
        return ans;
    }
};
