//直接计算
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int res = 0;
        for(int i = 0; i < n; ++i) res += mat[i][i];
        for(int i = 0; i < n; ++i) res += mat[n-1-i][i];
        if(n & 1) res -= mat[n >> 1][n >> 1];
        return res;
    }
};
