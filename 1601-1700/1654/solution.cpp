//BFS，难点在于对右侧搜素上界的估计
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int, int> s;
        queue<tuple<int, int, int>> q;
        int m = 0;
        for(int f : forbidden) {
            s[f] = 0;
            m = max(m, f);
        }
        int ub = max(m + a, x) + b + 1;
        //int ub = a * b / __gcd(a, b) + x - 1; //这个估计太宽松了，会TLE
        s[0] = 0;
        q.push({0, 0, 0});
        while(!q.empty()) {
            auto [pos, step, last_dir] = q.front(); q.pop();
            if(pos == x) return step;
            if(pos + a < ub) {
                if(!s.count(pos + a) || s[pos + a] == -1) {
                    q.push({pos + a, step + 1, 1});
                    s[pos + a] = 0;
                }
            }
            if(pos - b >= 0 && last_dir != -1 && !s.count(pos - b)) {
                q.push({pos - b, step + 1, -1});
                s[pos - b] = -1;
            }
        }
        return -1;
    }
};
