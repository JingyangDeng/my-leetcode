//需要发现总reward最大为2*max(rewardValues)-1
//并想到对于奖励值的范围做dp,判定任一奖励值是否可达
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int m = rewardValues[rewardValues.size()-1];
        int res = 0;

        vector<int> dp(2*m, 0);
        dp[0] = 1;

        for(int r : rewardValues) for(int i = r; i < 2*r; ++i) dp[i] |= dp[i-r];
        for(int i = 0; i < 2*m; ++i) if(dp[i]) res = i;
        return res;
    }
};
