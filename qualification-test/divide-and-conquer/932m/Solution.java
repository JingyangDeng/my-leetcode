//执行用时：0 ms, 在所有 Java 提交中击败了100.00% 的用户
//内存消耗：38.1 MB, 在所有 Java 提交中击败了64.58% 的用户 

//可将奇数放在一边，偶数放在一边，分治递归处理
class Solution {
    public int[] beautifulArray(int n) {
        if(n == 1) return new int[] {1};
        int evenNum = n / 2;
        int oddNum = (n + 1) / 2;
        int[] evenRet = beautifulArray(evenNum);
        int[] oddRet = beautifulArray(oddNum);
        int[] ret = new int[n];
        for(int i = 0; i < n; i++){
            if(i < evenNum) ret[i] = 2 * evenRet[i];
            else ret[i] = 2 * oddRet[i-evenNum] - 1;
        }
        return ret;
    }
}
