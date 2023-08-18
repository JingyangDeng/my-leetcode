//二维dp，记忆化搜索实现
//题目等价于选出n/3个不相邻数的最大和，分类讨论端点处是否被选即可
class Solution {
    vector<vector<vector<int>>> dp;
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        dp.resize(n, vector<vector<int>>(n/3+1, vector<int>(2, 0)));
        return max(dfs(slices, 1, n/3, 0), dfs(slices, 2, n/3-1, 1));
    }

    int dfs(vector<int>& slices, int begin, int num, int state) {
        if(num == 0) return state == 1 ? slices[0] : 0;
        if(begin >= slices.size()) return 0;
        if(begin == slices.size()-1 && state == 1) return 0;
        if(dp[begin][num][state] > 0) return dp[begin][num][state];
        return dp[begin][num][state] = max(dfs(slices, begin+1, num, state), slices[begin] + dfs(slices, begin+2, num-1, state));
    }
};
