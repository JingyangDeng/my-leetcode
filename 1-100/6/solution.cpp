//注：本题也可考察下标的关系直接构造,此时空间复杂度为O(1)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int r = (numRows - 1) << 1;
        vector<vector<char>> tmp(numRows, vector<char>());
        string ret(s.size(), '-');
        for (int i = 0; i < s.size(); ++i) {
            tmp[min(i % r, r - i % r)].emplace_back(s[i]);
        }
        int p = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < tmp[i].size(); ++j) {
                ret[p++] = tmp[i][j];
            }
        }
        return ret;
    }
};
