//排序
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        double ret = 0;
        for(int i = n / 20; i < 19 * n / 20; ++i){
            ret += arr[i];
        }
        ret /= (9 * n / 10);
        return ret;
    }
};
