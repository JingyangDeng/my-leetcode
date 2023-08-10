// 考虑是否将第i个数前面加负号
// 实际上即求有几种方法选出一些数和为(sum - target)/2
// 二维动态规划求解
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        if(nums.length == 1){
            if(target == nums[0] || target == -nums[0]) return 1;
            else return 0;
        }
        int sum = 0;
        for(int n : nums) sum += n;
        if(target > sum) return 0;
        if(((target - sum) & 1) == 1) return 0;
        target = (sum - target) >> 1;
        int[][] arr = new int[nums.length][target + 1];
        arr[0][0] += 1;
        if(nums[0] <= target) arr[0][nums[0]] += 1;
        for(int i = 1; i < nums.length; ++i){
            for(int j = 0; j <= target; ++j){
                arr[i][j] += arr[i - 1][j];
                if(j >= nums[i]) arr[i][j] += arr[i - 1][j - nums[i]];
            }
        }
        return arr[nums.length - 1][target];
    }
}

