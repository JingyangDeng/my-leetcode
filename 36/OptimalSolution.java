//多张hash表，一次遍历
class OptimalSolution {
    public boolean isValidSudoku(char[][] board) {
        int[][] cols = new int[9][9];
        int[][] rows = new int[9][9];
        int[][] boxs = new int[9][9];
        char ch;
        int bi, bj, b, key;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                ch = board[i][j];
                if(ch == '.') continue;

                bi = i / 3; bj = j / 3; b = bi * 3 + bj;
                key = ch - '1';

                if(rows[i][key] > 0 || cols[j][key] > 0 || boxs[b][key] > 0) return false;

                rows[i][key]++;
                cols[j][key]++;
                boxs[b][key]++;
            }
        }
        return true;
    }
}
