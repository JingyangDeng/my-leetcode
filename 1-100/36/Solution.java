//简单地遍历，依次检查行、列、九宫格
class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i = 0; i < 9; i++){
            int[] chars = new int[10];
            for(int j = 0; j < 9; j++){
                if(board[i][j] >= '0' && board[i][j] <= '9'){
                    if(chars[board[i][j] - '0'] == 1) return false;
                    chars[board[i][j] - '0'] = 1;
                }
            }
        }

        for(int j = 0; j < 9; j++){
            int[] chars = new int[10];
            for(int i = 0; i < 9; i++){
                if(board[i][j] >= '0' && board[i][j] <= '9'){
                    if(chars[board[i][j] - '0'] == 1) return false;
                    chars[board[i][j] - '0'] = 1;
                }
            }
        }

        for(int box = 0; box < 9; box++){
            int bx = box % 3;
            int by = box / 3;
            int[] chars = new int[10];
            for(int pos = 0; pos < 9; pos++){
                int i =  pos % 3 + bx * 3;
                int j =  pos / 3 + by * 3;
                if(board[i][j] >= '0' && board[i][j] <= '9'){
                    if(chars[board[i][j] - '0'] == 1) return false;
                    chars[board[i][j] - '0'] = 1;
                }
            }
        }

        return true;
    }
}
