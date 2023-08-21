//找间距的最大值，注意两边边界情况，O(n)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int last = -1;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(seats[i]) {
                if(last < 0) res = i;
                else res = max(res, (i - last) >> 1);
                last = i;
            }
        }
        res = max(res, n - last - 1);
        return res;
    }
};
