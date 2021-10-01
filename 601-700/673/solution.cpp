//执行用时：52 ms, 在所有 C++ 提交中击败了97.54% 的用户
//内存消耗：15.4 MB, 在所有 C++ 提交中击败了5.11% 的用户
//绝大部分提交内存在13000KB-13500KB之间，差距不大
//
// for i <- nums.size()-1 down to 1 by -1，考虑以i开头的最长递增子列的长度与个数
//使用动态规划+multimap二分查找优化，但最坏情况仍为O(n^2)
// dp的key为最长递增子列的长度，multimap的first为子列的第一项，second为最长子列的个数
class Solution {
public:
    unordered_map<int, multimap<int, int>> dp = {};
    int max_len = 0;

    int findNumberOfLIS(vector<int>& nums) {
        int ret = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            deal(max_len, nums[i]);
        }

        for (auto [num, cnt] : dp[max_len]) {
            ret += cnt;
        }

        return ret;
    }

    void deal(int len, int num) {
        if (!len) {
            dp[len + 1].insert(make_pair(num, 1));
            max_len = max(max_len, len + 1);
            return;
        }

        auto it = dp[len].upper_bound(num);
        if (it != dp[len].end()) {
            int cnt = 0;
            for (auto i = it; i != dp[len].end(); i++) {
                cnt += i->second;
            }
            dp[len + 1].insert(make_pair(num, cnt));
            max_len = max(max_len, len + 1);
            return;
        }

        deal(len - 1, num);
        return;
    }
};
