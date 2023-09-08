//拓扑排序判环
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            ++indegree[pre[0]];
        }
        int top = -1;
        for(int i = 0; i < numCourses; ++i){
            if(!indegree[i]) {
                indegree[i] = top;
                top = i;
            }
        }
        int complete = 0;
        while(top != -1){
            int v = top;
            ++complete;
            top = indegree[top];
            for(auto w : adj[v]){
                --indegree[w];
                if(!indegree[w]) {
                    indegree[w] = top;
                    top = w;
                }
            }
        }
        return complete == numCourses;
    }
};
