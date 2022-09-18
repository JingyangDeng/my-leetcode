//哈希+排序
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int n : nums) {
            cnt[n]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return cnt[a] < cnt[b] || (cnt[a] == cnt[b] && a > b);
        });
        return nums;
    }
};
