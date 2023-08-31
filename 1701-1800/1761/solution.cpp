//枚举所有的三元组
//n较小，使用邻接矩阵较快
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int res = INT_MAX;
        vector<int> deg(n, 0);
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for(auto& e : edges) {
            ++deg[e[0]-1]; ++deg[e[1]-1];
            adj[e[0]-1][e[1]-1] = 1; adj[e[1]-1][e[0]-1] = 1;
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                if(adj[i][j]) for(int k = j+1; k < n; ++k) {
                    if(adj[j][k] && adj[k][i]) {
                        res = min(res, deg[i] + deg[j] + deg[k] - 6);
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
