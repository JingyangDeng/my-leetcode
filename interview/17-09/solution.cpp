//优先队列
//注此题可有O(k)的算法
//dp[i] = min{dp[p1]*3, dp[p2]*5, dp[p3]*7}，维护三个指针p1~p3
class Solution {
public:
    int getKthMagicNumber(int k) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        unordered_set<long long> s;
        vector<int> factor = {3, 5, 7};
        long long ret = -1;
        q.push(1);
        s.insert(1);
        for(int i = 0; i < k; ++i){
            ret = q.top(); q.pop();
            for(int j = 0; j < 3; ++j){
                long long tmp = ret * factor[j];
                if(!s.count(tmp)) {
                    s.insert(tmp);
                    q.push(tmp);
                }
            }
        }
        return ret;
    }
};
