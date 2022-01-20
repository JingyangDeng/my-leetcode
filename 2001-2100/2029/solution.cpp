class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0);
        for (int s : stones) {
            ++cnt[s % 3];
        }
        if ((cnt[0] & 1)) {
            return abs(cnt[1] - cnt[2]) >= 3;
        }
        return cnt[1] && cnt[2];
    }
};
