//题目数据量不大，可直接双循环求解
//使用滑动窗口可将复杂度从O(nk)优化至O(n)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ret(n, 0);
        if(!k) return ret;
        if(k > 0){
            for(int i = 0; i < n; ++i){
                int su = 0;
                for(int j = 1; j <= k; ++j){
                    int ptr = i + j >= n ? i + j - n : i + j;
                    su += code[ptr];
                }
                ret[i] = su;
            }
        } else {
            for(int i = 0; i < n; ++i){
                int su = 0;
                for(int j = 1; j <= -k; ++j){
                    int ptr = i - j < 0 ? i - j + n : i - j;
                    su += code[ptr];
                }
                ret[i] = su;
            }
        }
        return ret;
    }
};
