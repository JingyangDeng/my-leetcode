// 模拟球从上至下列号的变化
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ret(n);
        for (int j = 0; j < n; ++j) {
            int col = j;
            for (auto& row : grid) {
                int dir = row[col];
                col += dir;
                if (col < 0 || col == n || row[col] != dir) {
                    col = -1;
                    break;
                }
            }
            ret[j] = col;
        }
        return ret;
    }
};
