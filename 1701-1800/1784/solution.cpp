//检查是否出现“01”字串
class Solution {
public:
    bool checkOnesSegment(string s) {
        int p = 0;
        while(p < s.size() && s[p] == '1') ++p;
        while(p < s.size() && s[p] == '0') ++p;
        return p == s.size();
    }
};
