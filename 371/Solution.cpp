//位运算，模仿补码进位加法
class Solution {
public:
    int getSum(int a, int b) {
        unsigned int s, ret = 0;
        bool x, y, f = 0;
        for (int i = 0; i < 32; i++) {
            x = a & 1;
            y = b & 1;
            s = x ^ y ^ f;
            f = (x & y) | (y & f) | (f & x);

            ret |= (s << i);
            a >>= 1;
            b >>= 1;
        }
        return (int)ret;
    }
};
