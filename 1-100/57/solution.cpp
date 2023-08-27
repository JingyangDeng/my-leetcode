//二分找出应修改的地方
class Solution {
    int left_bs(vector<vector<int>>& intervals, int x) {
        int n = intervals.size();
        if(x < intervals[0][0]) return -1;
        int l = 0, r = n - 1, mid;
        while(l < r) {
            mid = (l + r + 1) >> 1;
            if(intervals[mid][0] > x) r = mid - 1;
            else l = mid;
        }
        return l;
    }

    int right_bs(vector<vector<int>>& intervals, int x) {
        int n = intervals.size();
        if(x > intervals[n - 1][1]) return n;
        int l = 0, r = n - 1, mid;
        while(l < r) {
            mid = (l + r) >> 1;
            if(intervals[mid][1] < x) l = mid + 1;
            else r = mid;
        }
        return l;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        if(!n) {
            res.emplace_back(newInterval);
            return res;
        }
        int l = left_bs(intervals, newInterval[0]);
        int r = right_bs(intervals, newInterval[1]);
        int a, b;
        if(l == -1 || intervals[l][1] < newInterval[0]) {
            ++l;
            a = newInterval[0];
        } else a = intervals[l][0];
        if(r == n || intervals[r][0] > newInterval[1]) {
            --r;
            b = newInterval[1];
        } else b = intervals[r][1];

        for(int i = 0; i < l; ++i) res.emplace_back(intervals[i]);
        res.emplace_back(vector<int> {a, b});
        for(int i = r + 1; i < n; ++i) res.emplace_back(intervals[i]);
        return res;
    }
};
