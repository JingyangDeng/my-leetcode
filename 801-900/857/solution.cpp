//贪心+优先队列
//题目所求的k个人满足max{wage_i / quality_i} * sum{quality_i}最小
//将n个人按{wage_i / quality_i}排序，并用优先队列维护sum{quality_i}，进行一次遍历求解即可
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, double>> workers;
        auto rcmp = [](pair<double, double>& a, pair<double, double>& b) {
            return a.second / a.first < b.second / b.first;
        };
        priority_queue<pair<double, double>> q;
        for(int i = 0; i < n; ++i) workers.push_back({quality[i], wage[i]});
        sort(workers.begin(), workers.end(), rcmp);

        int ptr = 0;
        double qsum = 0;
        double ret = INFINITY;
        while(ptr < n){
            q.push(workers[ptr]);
            qsum += workers[ptr].first;
            if(q.size() > k) {
                qsum -= q.top().first;
                q.pop();
            }
            if(q.size() == k){
                double r = workers[ptr].second / workers[ptr].first;
                ret = min(ret, r * qsum);
            }
            ++ptr;
        }
        return ret;
    }
};
