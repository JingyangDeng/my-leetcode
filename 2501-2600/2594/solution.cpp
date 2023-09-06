//估计下界+调整，至多调整n-1次，每次O(logn)，总复杂度O(nlogn)
//注：也可二分猜测答案，每个答案用O(n)验证，复杂度O(nlogL)，L为二分上界
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        double coef = 0;
        int n = ranks.size();
        vector<long long> ub(n, 0);
        for(int r : ranks) {
            coef += 1 / sqrt(r);
        }
        
        priority_queue<pair<long long, int>> q;
        int su = 0;
        long long res = 0;
        for(int i = 0; i < n; ++i) {
            ub[i] = floor(cars / coef / sqrt(ranks[i]));
            res = max(res, (long long)ranks[i] * ub[i] * ub[i]);
            q.push({-(long long)ranks[i] * (ub[i] + 1) * (ub[i] + 1), i});
            su += ub[i];
        }
        int k = cars - su;
        while(k > 0) {
            auto [t, i] = q.top(); q.pop();
            res = max(res, -t);
            ++ub[i];
            q.push({-(long long)ranks[i] * (ub[i] + 1) * (ub[i] + 1), i});
            --k;
        }
        return res;
    }
};
