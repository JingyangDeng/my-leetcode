// (m^2 + m)/2 >= n ==> m >= (-1+sqrt(1+8n))/2
class Solution {
public:
    int twoEggDrop(int n) {
        double res = (sqrt(1+8*n)-1)/2;
        //cout << res << endl;
        return ceil(res);
    }
};

