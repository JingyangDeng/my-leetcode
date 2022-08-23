//需要注意到所有满足条件的矩阵rank为2
//所有行只可能出现两种互补的情况
//计算最小移动次数只需要对一行一列来进行讨论
class Solution {
    int n;
    int sum;
    vector<int> row_idx;
    int hash(vector<int>& b){
        int ret = 0;
        for(int i : b){
            ret <<= 1;
            ret |= i;
        }
        return ret;
    }

    bool get_row_idx(vector<vector<int>>& board){
        int row1 = hash(board[0]);
        for(int i = 0; i < n; ++i){
            int row = hash(board[i]);
            if(row == row1){
                row_idx[i] = 1;
            } else if(row == sum - row1){
                row_idx[i] = 0;
            } else {
                return 0;
            }
        }
        return 1;
    }

    int moveTimes(vector<int>& b){
        int cnt = 0;
        int oddcnt = 0;
        for(int i = 0; i < n; ++i){
            cnt += b[i];
            if(i & 1) oddcnt += b[i];
        }
        if(abs(n - 2 * cnt) > 1) return -1;
        if(n & 1){
            if(n - 2 * cnt > 0) return (n >> 1) - oddcnt;
            else return (n >> 1) + 1 - cnt + oddcnt;
        }
        return min(oddcnt, (n >> 1) - oddcnt);
    }

public:
    int movesToChessboard(vector<vector<int>>& board) {
        n = board.size();
        sum = (1 << n) - 1;
        row_idx = vector<int>(n);
        if(!get_row_idx(board)) return -1;
        int c = moveTimes(board[0]);
        int r = moveTimes(row_idx);
        return c >= 0 && r >= 0 ? c + r : -1;
    }
};
