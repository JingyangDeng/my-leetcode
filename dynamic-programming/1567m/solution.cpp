// 分别考虑以第i个数字为结尾的 乘积为正数&负数的最长子数组的长度
// 空间复杂度可优化至O(1)
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0] > 0 ? 1 : 0;
        int ret = 0;
        vector<vector<int>> arr(n, vector<int>(2));
        arr[0][0] = nums[0] > 0 ? 1 : 0;
        arr[0][1] = nums[0] < 0 ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0) {
                arr[i][0] = arr[i - 1][0] + 1;
                arr[i][1] = arr[i - 1][1] > 0 ? arr[i - 1][1] + 1 : 0;
            } else if (nums[i] < 0) {
                arr[i][0] = arr[i - 1][1] > 0 ? arr[i - 1][1] + 1 : 0;
                arr[i][1] = arr[i - 1][0] + 1;
            } else {
                arr[i][0] = 0;
                arr[i][1] = 0;
            }
            ret = max(ret, arr[i][0]);
        }
        return ret;
    }
};
