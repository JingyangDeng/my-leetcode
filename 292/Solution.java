//简单的推理，考虑“必胜状态”与“必败状态”之间的转换即可
class Solution {
    public boolean canWinNim(int n) {
        return n % 4 != 0;
    }
}
