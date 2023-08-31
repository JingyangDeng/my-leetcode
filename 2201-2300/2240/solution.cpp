//枚举贵的笔买几支
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int u = max(cost1, cost2);
        int l = min(cost1, cost2);
        long long res = 0;
        for(int x = 0; x <= total / u; ++x) {
            res += (total - x * u) / l + 1;
        }
        return res;
    }
};
