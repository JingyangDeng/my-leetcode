// sort
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = INT_MAX;
        for(int i = 0; i < n/2; ++i) {
            sum = min(sum, nums[i] + nums[n-1-i]);
        }
        return (double)sum / 2;
    }
};
