//使用hash表记录每次的余数，若有相同则为循环小数
//注意除法有正负，-2147483648取相反数会溢出
using ll = long long;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        ll num = numerator;
        ll denom = denominator;
        if (num == 0)
            return "0";
        unordered_map<int, int> s = {};
        int sgn = 1;
        if (num < 0) {
            num = -num;
            sgn = -sgn;
        }
        if (denom < 0) {
            denom = -denom;
            sgn = -sgn;
        }
        ll n = num / denom;
        ll r = num % denom;
        if (r == 0)
            return (sgn > 0 ? "" : "-") + to_string(n);

        string f = "";
        int p = 0;
        while (s.find(r) == s.end()) {
            s[r] = p++;
            r *= 10;
            f += to_string(r / denom);
            r %= denom;
            if (r == 0)
                return (sgn > 0 ? "" : "-") + to_string(n) + "." + f;
        }
        return (sgn > 0 ? "" : "-") + to_string(n) + "." + f.substr(0, s[r]) + "(" + f.substr(s[r]) + ")";
    }
};
