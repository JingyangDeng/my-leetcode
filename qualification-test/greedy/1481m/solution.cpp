//贪心法，按元素个数从小往大删除即可
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> counter;
        multiset<int> s;
        for (auto n : arr) {
            counter[n]++;
        }
        for (auto [k, v] : counter) {
            s.emplace(v);
        }
        int ret = s.size();
        for (auto it = s.begin(); it != s.end(); it++) {
            if (k > *it) {
                k -= *it;
                ret--;
            } else {
                if (k == *it)
                    ret--;
                break;
            }
        }
        return ret;
    }
};
