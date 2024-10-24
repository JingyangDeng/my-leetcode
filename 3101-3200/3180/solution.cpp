//BFS, MLE
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int res = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            auto [sum, start] = q.front();
            q.pop();
            //int l = find_l(rewardValues, sum, start);
            int l = start, r = rewardValues.size()-1;
            //if (rewardValues[r] <= sum) continue;
            while(l < r) {
                int tmp = (l + r) >> 1;
                if(rewardValues[tmp] <= sum) {
                    l = tmp + 1;
                } else {
                    r = tmp;
                }
            }
            //cout << sum << " " << start << " " << l << endl;
            for(int i = l; i < rewardValues.size(); ++i) {
                
                res = max(res, sum + rewardValues[i]);
                if(rewardValues[rewardValues.size()-1] <= sum + rewardValues[i]) continue;
                q.push({sum + rewardValues[i], i+1});
            }
        }
        return res;
    }
};
