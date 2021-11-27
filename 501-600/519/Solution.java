// 直接使用Fisher-Yates洗牌算法会超内存，用HashMap来存储下标
class Solution {
    Random r = new Random();
    HashMap<Integer, Integer> hMap;
    int m, n, p;
    public Solution(int m, int n) {
        this.m = m;
        this.n = n;
        hMap = new HashMap<>();
        p = m * n;
    }
    
    public int[] flip() {
        int k = r.nextInt(p);
        int tmp = hMap.getOrDefault(k, k);
        --p;
        hMap.put(k, hMap.getOrDefault(p, p));
        hMap.put(p, tmp);
        
        int[] ret = new int[2];
        ret[1] = tmp % n;
        ret[0] = tmp / n;
        return ret;
    }
    
    public void reset() {
        p = m * n;
        hMap.clear();
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(m, n);
 * int[] param_1 = obj.flip();
 * obj.reset();
 */
