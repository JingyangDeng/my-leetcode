//类似快速乘的思想，注意int的溢出情况
class Solution {
public:
    int divide(int dividend, int divisor) {
        return (int)dividell((long long)dividend, (long long)divisor);
    }
    long long dividell(long long dividend, long long divisor) {
        if (dividend == -2147483648 && divisor == -1)
            return 2147483647;
        if (dividend < 0) {
            if (divisor < 0)
                return dividell(-dividend, -divisor);
            else
                return -dividell(-dividend, divisor);
        } else if (divisor < 0) {
            return -dividell(dividend, -divisor);
        }
        long long sum = divisor;
        vector<long long> sums = {};
        while (sum <= dividend) {
            sums.emplace_back(sum);
            sum += sum;
        }
        int p = sums.size() - 1;
        long long ret = 0;
        while (p >= 0) {
            if (dividend >= sums[p]) {
                dividend -= sums[p];
                ret += ((long long)1 << p);
            }
            p--;
        }
        return ret;
    }
};
