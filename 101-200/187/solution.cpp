//状态压缩+hash+滑窗
class Solution {
private:
    string res = "AAAAAAAAAA";
    unordered_map<char, int> dic{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    char table[4] = {'A', 'C', 'G', 'T'};
    const string& decode(int code) {
        for (int i = 9; i >= 0; i--) {
            res[i] = table[code & 3];
            code >>= 2;
        }
        return res;
    }

public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret(0);
        if (s.size() < 10)
            return ret;
        unordered_map<int, int> mem = {};
        int code = 0;
        for (int i = 0; i < 10; i++) {
            code <<= 2;
            code += dic[s[i]];
        }
        mem[code] = 1;
        for (int i = 1; i < s.size() - 9; i++) {
            code &= 0x3ffff;
            code <<= 2;
            code += dic[s[i + 9]];
            mem[code]++;
            if (mem[code] == 2) {
                ret.emplace_back(decode(code));
            }
        }
        return ret;
    }
};
