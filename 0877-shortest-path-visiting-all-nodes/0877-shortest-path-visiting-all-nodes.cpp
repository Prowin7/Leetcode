class Solution {
    typedef pair<int,int> P;
public:

    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1||n==0) return 0;
        queue<P> q; // {node,mask}
        set<pair<int,int>> vis; //{node,pathMask}
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            q.push({i,mask});
            vis.insert({i,mask});
        }
        int fullPath=(1<<n)-1;
        int path=0;
        while(!q.empty()){
            int s=q.size();
            path++;
            while(s--){
                int currNode=q.front().first;
                int currMask=q.front().second;
                q.pop();
                for(auto it:graph[currNode]){
                    int newMask=currMask|(1<<it);
                    if(newMask==fullPath) return path;
                    if(vis.find({it,newMask})==vis.end()) {
                        vis.insert({it,newMask});
                        q.push({it,newMask});
                    }
                }
            }
        }

        return -1;
    }
};