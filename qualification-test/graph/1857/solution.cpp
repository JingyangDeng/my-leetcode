//拓扑排序+动态规划
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n, vector<int>());
        vector<int> indegree(n, 0);
        vector<int> toporder(n);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            ++indegree[e[1]];
        }
        int top = -1;
        for(int v = 0; v < n; ++v){
            if(!indegree[v]) {
                indegree[v] = top;
                top = v;
            }
        }
        int num = 0;
        while(top != -1){
            int v = top; top = indegree[top];
            toporder[num++] = v;
            for(int w : adj[v]) {
                --indegree[w];
                if(!indegree[w]) {
                    indegree[w] = top;
                    top = w;
                }
            }
        }
        if(num < n) return -1;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        for(int v = 0; v < n; ++v){
            dp[v][colors[v]-'a'] = 1;
        }
        for(int i = 0; i < n; ++i){
            int v = toporder[i];
            for(int w : adj[v]){
                for(int j = 0; j < 26; ++j){
                    if(colors[w]-'a' == j) dp[w][j] = max(dp[w][j], dp[v][j] + 1);
                    else dp[w][j] = max(dp[w][j], dp[v][j]);
                }
            }
        }
        int ret = 0;
        for(int v = 0; v < n; ++v){
            for(int j = 0; j < 26; ++j) ret = max(ret, dp[v][j]);
        }
        return ret;
    }
};
