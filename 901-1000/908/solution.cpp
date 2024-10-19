class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int m = INT_MIN, n = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            m = max(m, nums[i]);
            n = min(n, nums[i]);
        }
        return max(0, m-n-2*k);
    }
};
