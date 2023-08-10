//两次Kanade算法 同时求最大最小子序列和，注意所有数均为负数的特例
class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int sum = 0;
        int max = -1 << 30, min = 1 << 30, cur_max = -1 << 30, cur_min = 1 << 30;
        boolean f = true;
        for(int n : nums){
            if(n >= 0) f = false;
            cur_max = cur_max > 0 ? cur_max + n : n;
            cur_min = cur_min < 0 ? cur_min + n : n;
            max = Math.max(max, cur_max);
            min = Math.min(min, cur_min);
            sum += n;
        }
        if(f) return max;
        return Math.max(max, sum - min);
    }
}
