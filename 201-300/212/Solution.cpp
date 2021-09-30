// dfs+查找优化+未在board中出现的字符剪枝，由于数据较简单通过了。
// 此解法适用于board较大，而words长度较小的情况
// 执行用时：88 ms, 在所有 C++ 提交中击败了83.94% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了97.27% 的用户
class Solution {
public:
    int m, n;
    unordered_map<char, unordered_set<int>> position_info = {};
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> visited;
    vector<string> ret = {};

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        init(board);

        for (string w : words) {
            if (exists(board, w))
                ret.emplace_back(w);
        }

        return ret;
    }

    void init(const vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();

        visited.resize(m, vector<int>(n, 0));

        //记录每个字符出现在了哪些位置
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                position_info[board[i][j]].insert(i * n + j);
            }
        }
    }

    bool is_valid(const vector<vector<char>>& board, int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    bool exists(const vector<vector<char>>& board, const string& w) {
        int i, j;

        //若单词中有字符不在board中，直接返回false
        for (char c : w) {
            if (position_info.find(c) == position_info.end())
                return false;
        }

        for (int pos : position_info[w[0]]) {
            i = pos / n;
            j = pos % n;

            if (dfs(board, w, 0, i, j))
                return true;
        }
        return false;
    }

    bool dfs(const vector<vector<char>>& board, const string& w, int p, int i, int j) {

        if (p == w.size() - 1)
            return true;

        visited[i][j] = 1;
        int new_i, new_j;
        for (auto [di, dj] : dir) {
            new_i = i + di;
            new_j = j + dj;

            if (is_valid(board, new_i, new_j) && visited[new_i][new_j] == 0) {
                //根据hashmap查找目标位置是否为想要的字符
                if (position_info[w[p + 1]].find(new_i * n + new_j) != position_info[w[p + 1]].end()) {
                    if (dfs(board, w, p + 1, new_i, new_j)) {
                        visited[i][j] = 0;
                        return true;
                    }
                }
            }
        }
        visited[i][j] = 0;
        return false;
    }
};
