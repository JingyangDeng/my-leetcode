//二次方程求根
class Solution {
public:
    int arrangeCoins(int n) {
        // k^2 + k - 2n <= 0
        // k <= (-1 + sqrt(1 + 8n)) / 2
        return (int)((sqrt(8 * (double)n + 1) - 1) / 2);
    }
};
