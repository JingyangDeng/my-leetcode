//使用行 列标记向量
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> fRow(m);
        vector<int> fCol(n);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                if(!matrix[i][j]) {
                    fRow[i] = 1;
                    fCol[j] = 1;
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(fRow[i] || fCol[j]) matrix[i][j] = 0;
            }
        }
        return;
    }
};
