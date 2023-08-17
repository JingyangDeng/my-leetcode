//三维动态规划，考察每个右下子矩形切0,1,2,...,k-1刀的方法
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<int>> nums(m, vector<int>(n, 0));
        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                int a = i+1 < m ? nums[i+1][j] : 0;
                int b = j+1 < n ? nums[i][j+1] : 0;
                int c = i+1 < m && j+1 < n ? nums[i+1][j+1] : 0;
                int d = pizza[i][j] == 'A' ? 1 : 0;
                nums[i][j] = a + b - c + d;
            }
        }

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        for(int l = k-1; l >= 0; --l) {
            for(int i = m-1; i >= 0; --i) {
                for(int j = n-1; j >= 0; --j) {
                    if(l == k-1) {
                        dp[i][j][l] = nums[i][j] > 0 ? 1 : 0;
                    } else {
                        for(int p = i+1; p < m; ++p) {
                            if(nums[p][j] < nums[i][j]) {
                                dp[i][j][l] += dp[p][j][l+1];
                                dp[i][j][l] %= 1000000007;
                            }
                        }
                        for(int p = j+1; p < n; ++p) {
                            if(nums[i][p] < nums[i][j]) {
                                dp[i][j][l] += dp[i][p][l+1];
                                dp[i][j][l] %= 1000000007;
                            }
                        }
                    }
                }
            }
        }

        return dp[0][0][0];
    }
};
