//not optimal, O(n^2 * m), m = min(n(n-1)/2, maxcnt)
//there exists a O(mn*min(maxcnt, n)) solution
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        int m = min(n*(n-1)/2, 400);

        // a个不同的数，逆序数为cnt,可能的组合数为interior[a][cnt]
        vector<vector<long long>> interior(n+1, vector<long long>(m+1, -1)); 
        // a+b个不同的数，前a与后b个数的交叉逆序数为cnt,可能的划分数为cross[a][b][cnt]
        vector<vector<vector<long long>>> cross(n+1, vector<vector<long long>>(n+1, vector<long long>(m+1, -1)));

        for(int j = 0; j <= m; ++j) {
            interior[1][j] = (j == 0 ? 1 : 0);
            cross[0][0][j] = (j == 0 ? 1 : 0);
            for(int i = 1; i <= n; ++i) {
                cross[0][i][j] = (j == 0 ? 1 : 0) % 1000000007;
                cross[i][0][j] = (j == 0 ? 1 : 0) % 1000000007;
            }
        }

        for(int i = 2; i <= n; ++i) {
            for(int c = 0; c <= m; ++c) {
                interior[i][c] = 0;
                for(int k = 0; k < i; ++k) {
                    if(c-k >= 0) {
                        interior[i][c] += interior[i-1][c-k];
                        interior[i][c] %= 1000000007;
                    }
                }
            }
        }

        for(int i = 2; i <= n; ++i) {
            for(int a = 1; a < i; ++a) {
                for(int c = 0; c <= m; ++c) {
                    cross[a][i-a][c] = cross[a-1][i-a][c];
                    cross[a][i-a][c] %= 1000000007;
                    if(c-a >= 0) {
                        cross[a][i-a][c] += cross[a][i-a-1][c-a];
                        cross[a][i-a][c] %= 1000000007;
                    }
                }
            }
        }
        
        int r = requirements.size();
        sort(requirements.begin(), requirements.end(), [](vector<int> a, vector<int> b) {return a[0] > b[0];});
        
        long long res = interior[requirements[r-1][0]+1][requirements[r-1][1]];
        for(int i = 1; i < requirements.size(); ++i) {
            int a = requirements[i][0] + 1;
            int b = requirements[i-1][0] - requirements[i][0];
            int c = requirements[i-1][1] - requirements[i][1];
            long long tmp = 0;
            for(int self = 0; self <= c; ++self) {
                tmp += interior[b][self] * cross[a][b][c-self];
                tmp %= 1000000007;
            }
            res *= tmp;
            res %= 1000000007;
        }
        return res;
    }
};
