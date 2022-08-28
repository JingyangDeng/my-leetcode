//注意到答案只可能为0或5,以及f(x)是单调函数
//使用二分查找是否存在x使f(x)=k即可
class Solution {
public:
    long long f(long long x) {
        long long ret = 0;
        while(x) {
            x /= 5;
            ret += x;
        }
        return ret;
    }

    bool canFindX(int k, long long low, long long high) {
        if(low > high) return false;
        long long mid = (low + high) >> 1;
        long long tmp = f(mid);
        if(tmp == k) return true;
        if(tmp < k) return canFindX(k, mid+1, high);
        return canFindX(k, low, mid-1);
    }

    int preimageSizeFZF(int k) {
        return canFindX(k, 0, 5 * (long long)k) ? 5 : 0;
    }
};
