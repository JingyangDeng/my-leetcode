// 记f[i]为从i出发所需要的最少花费
// f[i] = cost[i] + min(f[i+1], f[i+2])
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] arr = new int[n + 1];
        arr[n] = 0;
        arr[n - 1] = cost[n - 1];
        arr[n - 2] = cost[n - 2];
        for(int i = n - 3; i >= 0; --i){
            arr[i] = cost[i] + Math.min(arr[i + 1], arr[i + 2]);
        }
        return Math.min(arr[0], arr[1]);
    }
}
