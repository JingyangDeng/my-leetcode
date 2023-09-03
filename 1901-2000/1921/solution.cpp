//贪心，优先消灭最快到达的怪物
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n, 0);
        for(int i = 0; i < n; ++i) {
            time[i] = (double)dist[i] / speed[i];
        }
        sort(time.begin(), time.end());
        int res = n;
        for(int i = 0; i < n; ++i) {
            if(time[i] <= i) {
                res = i; break;
            }
        }
        return res;
    }
};
