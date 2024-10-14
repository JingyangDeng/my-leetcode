class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        // 1 + 3 + 5 + ... + (2n-1) = n^2
        // 2 + 4 + 6 + ... + 2n = n^2 + n
        int m = min(red, blue);
        int n = max(red, blue);

        int res = -1;
        
        // m odd
        int odd = floor(sqrt(m));
        if(odd * odd + odd <= n) {
            res = 2 * odd;
        } else {
            res = 2 * odd - 1;
        }

        // m even
        int even = floor((sqrt(1+4*m)-1)/2);
        if((even+1)*(even+1) <= n) {
            res = max(res, 2*even+1);
        } else {
            res = max(res, 2*even);
        }

        return res;
    }
};
