//统计连续0的个数，验证两端是否为{-1, 1}
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int res = 0;
        int n = forts.size();
        int i = 0, latest = -1;
        while(i < n) {
            while(i < n && forts[i] == 0) ++i;
            if(i < n && latest >= 0 && forts[i] + forts[latest] == 0) res = max(res, i - latest - 1);
            latest = i++;
        }
        return res;
    }
};
