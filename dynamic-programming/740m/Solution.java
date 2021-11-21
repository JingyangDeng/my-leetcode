// 考虑只从0~i中选择数字能获取的最大值
// f[i] = max(f[i-1], f[i-2] + cnt[i]*i)
class Solution {
    public int deleteAndEarn(int[] nums) {
        TreeMap<Integer, Integer> m = new TreeMap<>();
        for(int n : nums){
            m.put(n, m.getOrDefault(n, 0) + 1);
        }
        int[][] last = new int[2][2];
        for(int k : m.keySet()){
            if(last[0][0] == -1){
                last[0][0] = k;
                last[0][1] = k * m.get(k);
                continue;
            }
            int tmp = 0;
            if(last[0][0] == k - 1){
                if(last[1][0] == -1){
                    tmp = Math.max(k * m.get(k), last[0][1]);
                } else {
                    tmp = Math.max(k * m.get(k) + last[1][1], last[0][1]);
                }
            } else {
                tmp = k * m.get(k) + last[0][1];
            }
            last[1][0] = last[0][0];
            last[1][1] = last[0][1];
            last[0][0] = k;
            last[0][1] = tmp;
        }
        return last[0][1];
    }
}
