//排序 贪心
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ret;
        int sum = 0;
        for(int n : nums){
            sum += n;
        }
        int cur = 0;
        for(int i = nums.size()-1; i >= 0; --i){
            if(2 * cur <= sum){
                ret.emplace_back(nums[i]);
            } else break;
            cur += nums[i];
        }
        return ret;
    }
};
