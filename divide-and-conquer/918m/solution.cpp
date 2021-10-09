// Kanade算法同时求最大最小子区间和，答案为max和sum-min的较大值
// 注意排除所有数均为负数导致sum=min的情况
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int mmin = INT32_MAX;
        int mmax = INT32_MIN;
        int su = 0;
        int curmax = INT32_MIN;
        int curmin = INT32_MAX;
        bool f = true;
        for (auto x : A) {
            if (x >= 0)
                f = false;
            su += x;
            curmax = curmax >= 0 ? x + curmax : x;
            curmin = curmin <= 0 ? x + curmin : x;
            mmin = min(mmin, curmin);
            mmax = max(mmax, curmax);
        }
        if (f)
            return mmax;
        int ret = max(mmax, su - mmin);
        return ret;
    }
};
