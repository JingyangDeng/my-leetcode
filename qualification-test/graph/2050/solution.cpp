//拓扑排序+动态规划
//注：可以将二者合并在一起进行，即不需要先算出toponum再进行动态规划
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n+1, 0);
        vector<int> toponum(n, -1);
        vector<int> eft(n+1, 0);
        vector<vector<int>> adj(n+1);
        int ret = 0;
        for(int v = 1; v <= n; ++v){
            eft[v] = time[v-1];
            ret = max(ret, eft[v]);
        }
        for(auto& r : relations){
            adj[r[0]].push_back(r[1]);
            ++indegree[r[1]];
        }
        int top = -1;
        for(int v = 1; v <= n; ++v){
            if(!indegree[v]){
                indegree[v] = top;
                top = v;
            }
        }
        int no = 0;
        while(top != -1){
            int v = top;
            toponum[no++] = v;
            top = indegree[top];
            for(auto w : adj[v]){
                --indegree[w];
                if(!indegree[w]){
                    indegree[w] = top;
                    top = w;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            int v = toponum[i];
            for(auto w : adj[v]){
                eft[w] = max(eft[w], eft[v] + time[w-1]);
                ret = max(ret, eft[w]);
            }
        }
        return ret;
    }
};
