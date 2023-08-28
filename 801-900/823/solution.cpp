//动态规划
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        for(int i = 0; i < n; ++i) {
            dp[arr[i]] = 1;
            for(int j = 0; j < i; ++j) {
                if(arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j])) {
                    dp[arr[i]] += dp[arr[j]] * dp[arr[i] / arr[j]];
                    dp[arr[i]] %= 1000000007;
                }
            }
        }
        int res = 0;
        for(auto [k, v] : dp) {
            res += v;
            res %= 1000000007;
        }
        return res;
    }
};
