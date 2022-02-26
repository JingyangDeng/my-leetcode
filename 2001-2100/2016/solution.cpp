//另解：计算nums[i] - min(nums[0], ..., nums[i-1])的最大值
//一次遍历，空间复杂度O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        vector<int> m(nums.size(), INT_MAX);
        int cur = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            cur = min(cur, nums[i]);
            m[i] = cur;
        }
        int ret = -1;
        for(int i = nums.size() - 1; i > 0; --i){
            cur = max(cur, nums[i]);
            if(cur > m[i-1]) ret = max(ret, cur - m[i-1]);
        }
        return ret;
    }
};
