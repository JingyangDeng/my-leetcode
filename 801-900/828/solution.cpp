//动态规划，记以第i个字符结尾的所有字串的函数和为f[i]，考虑f[i]和f[i-1]的关系即可
class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, pair<int, int>> buf;
        for(int i = 0; i < 26; ++i){
            buf['A' + i] = {-1, -1};
        }
        int inc = 0;
        int ret = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            auto [first, second] = buf[s[i]];
            if(second == -1){
                inc += i + 1;
            } else if(first == -1){
                inc += i - second;
                inc -= second + 1;
            } else {
                inc += i - second;
                inc -= second - first;
            }
            ret += inc;
            buf[s[i]].first = second;
            buf[s[i]].second = i;
        }
        return ret;
    }
};
