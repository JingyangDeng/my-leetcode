// 考虑前i个数的最大 最小乘积 注意有负数和0
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = INT_MIN;
        int cur_max = INT_MIN;
        int cur_min = INT_MAX;
        int nxt_max, nxt_min;
        for (int n : nums) {
            if (n >= 0) {
                nxt_max = cur_max > 0 ? cur_max * n : n;
                nxt_min = cur_min <= 0 ? cur_min * n : n;
            } else {
                nxt_max = cur_min <= 0 ? cur_min * n : n;
                nxt_min = cur_max > 0 ? cur_max * n : n;
            }
            cur_max = nxt_max;
            cur_min = nxt_min;
            ret = max(ret, cur_max);
        }
        return ret;
    }
};
