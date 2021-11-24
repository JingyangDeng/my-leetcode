// 推理题
class Solution {
public:
    string originalDigits(string s) {
        vector<int> c(26);
        for (char ch : s) {
            ++c[ch - 'a'];
        }

        vector<int> cnt(10);
        cnt[0] = c['z' - 'a'];
        cnt[2] = c['w' - 'a'];
        cnt[4] = c['u' - 'a'];
        cnt[6] = c['x' - 'a'];
        cnt[8] = c['g' - 'a'];

        cnt[3] = c['h' - 'a'] - cnt[8];
        cnt[5] = c['f' - 'a'] - cnt[4];
        cnt[7] = c['s' - 'a'] - cnt[6];
        cnt[1] = c['o' - 'a'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = c['i' - 'a'] - cnt[5] - cnt[6] - cnt[8];

        string ret;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ret += i + '0';
            }
        }
        return ret;
    }
};
