//位运算
class Solution {
    public String toHex(int num) {
        if(num == 0) return "0";
        char[] c = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        char[] ret = new char[8];
        for(int i = 7; i >= 0; i--){
            int p = 0;
            for(int j = 0; j < 4; j++){
                p += ((num & 1) << j);
                num >>= 1;
            }
            ret[i] = c[p];
        }
        return new String(ret).replaceAll("^(0+)", "");
    }
}
