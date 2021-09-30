//简单的递归思想，a^543 = ((a^5)^10 * a^4)^10 * a^3
class Solution {
    int[] pow = new int[10];
    public int superPow(int a, int[] b) {
        if(b[0] == 0) return 1;
        a %= 1337;
        int prod = 1;
        for(int i = 0; i < 10; i++){
            pow[i] = prod;
            prod *= a;
            prod %= 1337;
        }

        int ret = 1;
        for(int i = 0; i < b.length; i++){
            int factor = ret;
            for(int j = 0; j < 9; j++){
                ret *= factor;
                ret %= 1337;
            }
            ret *= pow[b[i]];
            ret %= 1337;
        }
        return ret;
    }
}
