class Solution {
public:
    int superEggDrop(int k, int n) {
        // j: broken f(j-1, k-1), not broken f(n-j, k) 
        // f(n, k) = minj: 1 + max(f(j-1, k-1), f(n-j, k))

        // need to note that when j increases, f(j-1, k-1) increases and f(n-j, k) decreases

        // f(n, k) >= f(n-1, k), f(n, k) <= f(n, k-1)
        // j(n, k) < n/2 + 1, j(n, k-1) <= j(n, k), j(n-1, k) <= j(n, k)

        if(n == 1) return 1;
        if(k == 1) return n;

        vector<vector<int>> res(n+1, vector<int>(k+1));
        vector<vector<int>> pos(n+1, vector<int>(k+1));
        for(int ki = 1; ki <= k; ++ki) {
            res[1][ki] = 1;
            pos[1][ki] = 1;
        }
        for(int ni = 1; ni <= n; ++ni) {
            res[ni][1] = ni;
            pos[ni][1] = 1;
        }
        for(int ki = 2; ki <= k; ++ki) {
            int j = max(pos[2][ki-1], pos[1][ki]);
            for(int ni = 2; ni <= n; ++ni) {
                while(res[j-1][ki-1] < res[ni-j][ki]) ++j;
                if(res[j-1][ki-1] < res[ni-j+1][ki]) {
                    res[ni][ki] = res[j-1][ki-1];
                    pos[ni][ki] = j;
                } else {
                    res[ni][ki] = res[ni-j+1][ki];
                    pos[ni][ki] = j-1;
                }
                ++res[ni][ki];
            }
        }
        return res[n][k];
    }
};
