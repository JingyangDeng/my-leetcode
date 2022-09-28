// 若s2由s1旋转而得，则s2+s2必定有字串s1
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        return s1.size() == s2.size() && (s2 + s2).find(s1) != -1;
    }
};
