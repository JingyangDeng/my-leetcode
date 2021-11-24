// 数字推导 n猪 m次 => 至多能测(m+1)^n瓶药
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};
