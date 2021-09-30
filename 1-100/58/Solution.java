//简单反向遍历
class Solution {
    public int lengthOfLastWord(String s) {
        int p = s.length() - 1;
        int ret = 0;
        while(p >= 0 && s.charAt(p) == ' ') p--;
        while(p >= 0 && s.charAt(p) != ' '){
            p--; ret++;
        }
        return ret;
    }
}
