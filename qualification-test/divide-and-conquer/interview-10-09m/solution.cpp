//将矩阵斜过来看即为一颗二叉查找树
//复杂度O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m)
            return false;
        int n = matrix[0].size();
        if (!n)
            return false;
        int i = 0, j = n - 1;
        while (1) {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] < target) {
                if (i + 1 == m)
                    break;
                i++;
            } else {
                if (j == 0)
                    break;
                j--;
            }
        }
        return false;
    }
};
