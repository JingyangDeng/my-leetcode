//动态规划 O(n^3)
//可优化至 O(n^2)，只需要维护dp中每一行的最小值和次小值即可，不必再用一重循环
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); //dp[i][j]:以第i行j列结尾的最小数字和
        for(int j = 0; j < n; ++j) dp[0][j] = grid[0][j];
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int cur_min = INT_MAX;
                for(int k = 0; k < n; ++k) {
                    if(j == k) continue;
                    cur_min = min(cur_min, dp[i-1][k]);
                }
                dp[i][j] = cur_min + grid[i][j];
            }
        }
        int res = INT_MAX;
        for(int j = 0; j < n; ++j) res = min(res, dp[n-1][j]);
        return res;
    }
};
