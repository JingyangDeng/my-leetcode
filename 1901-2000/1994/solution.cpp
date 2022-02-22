class Solution {
public:
    // 2 3 5 7 11 13 17 19 23 29
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<long long> code(31, -1);
        code[1] = 0;
        code[2] = 1;
        code[3] = 2;
        code[5] = 4;
        code[6] = 3;
        code[7] = 8;
        code[10] = 5;
        code[11] = 16;
        code[13] = 32;
        code[14] = 9;
        code[15] = 6;
        code[17] = 64;
        code[19] = 128;
        code[21] = 10;
        code[22] = 17;
        code[23] = 256;
        code[26] = 33;
        code[29] = 512;
        code[30] = 7;

        vector<long long> cnt(31, 0);
        for (auto n : nums)
            ++cnt[n];

        vector<vector<long long>> dp(31, vector<long long>(1024, 0));

        for (int i = 2; i <= 30; ++i) {
            if (!cnt[i] || code[i] == -1)
                continue;
            dp[i][code[i]] += cnt[i];
            dp[i][code[i]] %= 1000000007;
            for (int cd = 0; cd + code[i] < 1024; ++cd) {
                if ((cd & code[i]))
                    continue;
                for (int j = 2; j < i; ++j) {
                    dp[i][cd + code[i]] += dp[j][cd] * cnt[i];
                    dp[i][cd + code[i]] %= 1000000007;
                }
            }
        }

        long long ret = 0;
        for (int i = 2; i < 31; ++i) {
            for (int cd = 0; cd < 1024; ++cd) {
                ret += dp[i][cd];
                ret %= 1000000007;
            }
        }

        for (int k = 0; k < cnt[1]; ++k) {
            ret *= 2;
            ret %= 1000000007;
        }

        return ret;
    }
};
