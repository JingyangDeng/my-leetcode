//正序+反序最长递增子序列，动态规划O(n^2)
//可优化至O(nlogn)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        for(int i = 1; i < n; ++i){
            int tmp = 0;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]) tmp = max(tmp, dp1[j]);
            }
            dp1[i] = tmp + 1;
        }
        for(int i = n - 2; i >= 0; --i){
            int tmp = 0;
            for(int j = i + 1; j < n; ++j){
                if(nums[i] > nums[j]) tmp = max(tmp, dp2[j]);
            }
            dp2[i] = tmp + 1;
        }
        int longest = 0;
        for(int i = 0; i < n; ++i){
            if(dp1[i] > 1 && dp2[i] > 1) longest = max(longest, dp1[i] + dp2[i] - 1);
        }
        return n - longest;
    }
};
