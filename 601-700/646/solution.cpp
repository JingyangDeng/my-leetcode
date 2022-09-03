//贪心
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp = [](vector<int>& x, vector<int>& y) -> bool {
            return x[1] < y[1];
        };
        sort(pairs.begin(), pairs.end(), cmp);

        int ret = 0;
        int cur = INT_MIN;
        for(int i = 0; i < pairs.size(); ++i){
            if(pairs[i][0] > cur){
                ++ret;
                cur = pairs[i][1];
            }
        }
        return ret;
    }
};
