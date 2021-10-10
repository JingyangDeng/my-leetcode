//快速排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt = {};
        vector<pair<int, int>> vec = {};
        vector<int> ret = {};
        for (int n : nums)
            cnt[n]++;
        for (auto [key, value] : cnt)
            vec.emplace_back(make_pair(-value, key));
        nth_element(vec.begin(), vec.begin() + k - 1, vec.end());
        for (auto it = vec.begin(); it != vec.begin() + k; it++)
            ret.emplace_back(it->second);
        return ret;
    }
};
