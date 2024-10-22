//使用cnt维护hours[i+1 ... n]中余数为0～23的分布
//从大到小遍历i,统计以i开头的标对数目, O(n)
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<long long> cnt(24, 0);
        long long res = 0;
        for(int i = hours.size() - 1; i >= 0; --i) {
            int bucket = hours[i] % 24;
            int target = bucket > 0 ? 24 - bucket : 0;
            res += cnt[target];
            ++cnt[bucket];
        }
        return res;
    }
};
