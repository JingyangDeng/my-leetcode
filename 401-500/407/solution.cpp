// mark
// 使用优先队列维护边界
// 找出边界上最小值的位置，往内部收缩
// 若内部高度h < h_minbound，则该点能接h_minbound - h的雨水，将其视为高度为h_minbound的边界加入队列
// 若h >= h_minbound，则该点不能接雨水，将其作为高度h的边界加入队列
// 直到所有位置都被访问后加入了队列 （使用visited数组避免重复访问）
//
// 执行用时：56 ms, 在所有 C++ 提交中击败了90.30% 的用户
// 内存消耗：13 .1 MB, 在所有 C++ 提交中击败了79 .01 % 的用户
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        int pos = 0;
        while (pos < m * n) {
            int i = pos / n;
            int j = pos % n;
            q.emplace(heightMap[i][j], pos);
            visited[i][j] = 1;
            if (i == 0 || j == n - 1 || i == m - 1)
                pos++;
            else
                pos += n - 1;
        }

        int ret = 0;
        while (!q.empty()) {
            auto [h, pos] = q.top();
            q.pop();
            int i = pos / n;
            int j = pos % n;
            for (auto [di, dj] : dir) {
                int ni = i + di;
                int nj = j + dj;
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && !visited[ni][nj]) {
                    int nh = heightMap[ni][nj];
                    if (nh < h) {
                        ret += h - nh;
                        nh = h;
                    }
                    visited[ni][nj] = 1;
                    q.emplace(nh, ni * n + nj);
                }
            }
        }
        return ret;
    }
};
