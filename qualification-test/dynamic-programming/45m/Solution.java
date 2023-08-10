// 动态规划，考虑从i开始到最后所需要的最小步数，复杂度O(n^2)
// 也可采取贪心法，每一步选择跳到“2跳最优”的位置
class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if(n == 1) return 0;
        int[] arr = new int[n];
        arr[n - 1] = 0;
        for(int i = n - 2; i >= 0; --i){
            int tmp = 1 << 30;
            for(int j = i + 1; j <= Math.min(n - 1, i + nums[i]); ++j){
                tmp = Math.min(tmp, arr[j]);
            }
            arr[i] = tmp + 1;
        }
        return arr[0];
    }
}

