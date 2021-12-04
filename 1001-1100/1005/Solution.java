//注意nums[i]是有界的，可使用桶排序在O(n)内完成排序
class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        int[] cnt = new int[201];
        int sum = 0;
        for(int n : nums){
            ++cnt[n + 100];
            sum += n;
        }
        int p = 0;
        while(k > 0 && p < 100){
            if(cnt[p] > 0){
                int op = Math.min(k, cnt[p]);
                cnt[p] -= op;
                cnt[200 - p] += op;
                sum += (200 - 2 * p) * op;
                k -= op;
            }
            ++p;
        }
        if(k > 0 && (k & 1) == 1){
            while(cnt[p] == 0) ++p;
            sum += (200 - 2 * p);
        }
        return sum;
    }
}

