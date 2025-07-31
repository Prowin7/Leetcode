class Solution { // we can use kahn's algorithm
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        vector<int> indegree(num);
        for(auto it:pre){
                adj[it[1]].push_back(it[0]);
                indegree[it[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < num; i++) {              
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==num) return ans;
        return {};
    }
};