// 暴力求解，注意到质数的范围<=19
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> s = {2, 3, 5, 7, 11, 13, 17, 19};
        int ret = 0;
        for(int i = left; i <= right; ++i){
            if(s.count(__builtin_popcount(i))) ++ret;
        }
        return ret;
    }
};
