//动态规划，求以当前数为结尾的最大等差子序列。
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int ret = 1;
        for (int n : arr) {
            int target = n - difference;
            if (m.find(target) == m.end()) {
                m[n] = 1;
                continue;
            }
            m[n] = m[target] + 1;
            ret = max(ret, m[n]);
        }
        return ret;
    }
};
