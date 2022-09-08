//以一大一小为基础构造
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int cnt = 0;
        vector<int> ret(n);
        int left = 1, right = n;
        int delta = 1, val = left;
        for(int i = 0; i < n; ++i){
            if(i == 0) {
                ret[i] = left++;
                continue;
            }
            if(cnt < k - 1){
                if(i & 1) ret[i] = right--;
                else ret[i] = left++;
                ++cnt;
                if(cnt == k - 1){
                    val = ret[i];
                    delta = (i & 1) ? -1 : 1;
                }
                continue;
            }
            val += delta;
            ret[i] = val;
        }
        return ret;
    }
};
