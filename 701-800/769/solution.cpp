//根据当前最大值确定当前块右侧的下界，贪心分块
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ret = 0, upper = 0;
        for(int i = 0; i < arr.size(); ++i){
            upper = max(upper, arr[i]);
            if(i == upper) ++ret;
        }
        return ret;
    }
};
