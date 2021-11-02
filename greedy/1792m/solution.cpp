//贪心+优先队列，比较每班增加一个学生所带来的通过率增量
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> q;
        double ret = 0;
        auto inc = [](int p, int t) -> double { return (double)(p + 1) / (t + 1) - (double)p / t; };
        for (auto& c : classes) {
            q.emplace(inc(c[0], c[1]), c[0], c[1]);
            ret += (double)c[0] / c[1];
        }
        while (extraStudents > 0) {
            auto [i, p, t] = q.top();
            q.pop();
            p++;
            t++;
            q.emplace(inc(p, t), p, t);
            ret += i;
            extraStudents--;
        }
        return ret / classes.size();
    }
};
