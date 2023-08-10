// 分是否选择第0家两类，考虑前i家中能得到的最大价值
// 空间复杂度可优化至O(1)
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        if(n == 2) return Math.max(nums[0], nums[1]);
        int[][] arr = new int[n][2];
        arr[0][0] = 0;
        arr[0][1] = nums[0];
        arr[1][0] = nums[1];
        arr[1][1] = nums[0];
        for(int i = 2; i < n - 1; ++i){
            arr[i][0] = Math.max(arr[i - 1][0], arr[i - 2][0] + nums[i]);
            arr[i][1] = Math.max(arr[i - 1][1], arr[i - 2][1] + nums[i]);
        }
        arr[n - 1][0] = Math.max(arr[n - 2][0], arr[n - 3][0] + nums[n - 1]);
        arr[n - 1][1] = arr[n - 2][1];
        return Math.max(arr[n - 1][0], arr[n - 1][1]);
    }
}
