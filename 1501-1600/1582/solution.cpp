//预处理计算行和与列和
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rSum(m, 0);
        vector<int> cSum(n, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                rSum[i] += mat[i][j];
                cSum[j] += mat[i][j];
            }
        }
        int ret = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] && rSum[i] == 1 && cSum[j] == 1) ++ret;
            }
        }
        return ret;
    }
};
