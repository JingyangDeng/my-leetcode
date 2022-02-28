// 回溯法，枚举所有情况
// ps：可用网络流算法，待学习
class Solution {
    int ret = 0, cur = 0;
    vector<int> cnt;

public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        cnt.resize(n, 0);
        dfs(requests, 0);
        return ret;
    }

    void dfs(vector<vector<int>>& requests, int k) {
        if (k == requests.size()) {
            for (int i = 0; i < cnt.size(); ++i) {
                if (cnt[i] != 0)
                    return;
            }
            ret = max(ret, cur);
            return;
        }
        // reject k
        dfs(requests, k + 1);

        // accept k
        --cnt[requests[k][0]];
        ++cnt[requests[k][1]];
        ++cur;
        dfs(requests, k + 1);
        // backtrack
        --cur;
        --cnt[requests[k][1]];
        ++cnt[requests[k][0]];
    }
};
