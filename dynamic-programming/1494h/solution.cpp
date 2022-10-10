//状态压缩+DP
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> pre(n, 0);
        vector<int> dp((1 << n), INT_MAX);
        for(auto& r : relations){
            int v = r[0] - 1;
            int w = r[1] - 1;
            pre[w] |= (1 << v);
        }
        dp[0] = 0;
        for(int status = 0; status < (1 << n); ++status){
            if(dp[status] == INT_MAX) continue;
            int aval = 0;
            //遍历查找当前状态下，本学期能上的课
            for(int i = 0; i < n; ++i){
                //若之前没上过，且所有先修课程都上过，则列为备选
                if(((1 << i) & status) == 0 && (pre[i] & status) == pre[i]){
                    aval |= (1 << i);
                }
            }
            //枚举备选集中<=k的子集
            for(int mask = aval; mask; mask = (mask-1) & aval){
                if(__builtin_popcount(mask) <= k){
                    dp[status | mask] = min(dp[status | mask], dp[status] + 1);
                }
            }
        }
        return dp[(1 << n)-1];
    }
};
