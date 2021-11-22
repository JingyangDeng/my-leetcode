// Fisher Yates 洗牌算法
class Solution {
    int[] arr;
    int n;
    Random r = new Random();
    public Solution(int[] nums) {
        arr = nums;
        n = arr.length;
    }
    
    public int[] reset() {
        return arr;
    }
    
    public int[] shuffle() {
        int[] ret = new int[n];
        for(int i = 0; i < n; ++i){
            ret[i] = arr[i];
        }
        for(int i = 0; i < n; ++i){
            int p = r.nextInt(n - i);
            int tmp = ret[n - i - 1];
            ret[n - i - 1] = ret[p];
            ret[p] = tmp;
        }
        return ret;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */

