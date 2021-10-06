//一次遍历，找到所有前一位是空格(或开头)，下一位不是空格的下标
class Solution {
public:
    int countSegments(string s) {
        int ret = 0;
        bool word = 0;
        for (char c : s) {
            if (!word && c != ' ') {
                word = 1;
                ret++;
            } else if (word && c == ' ')
                word = 0;
        }
        return ret;
    }
};
