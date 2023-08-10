// mark:
//贪心+树状数组+二分 O(n(logn)^2)
//先摆矮的，身高相同摆位置靠后的
//使用树状数组维护第i个座位（包括i）之前有几个位置已经被占了。
//需要找的位置pos应满足：pos = pos之前被占的座位数 + 应有的空位数，二分查找。
class Solution {
public:
    vector<int> arr;
    void add(int pos) {
        pos++;
        while (pos < arr.size()) {
            arr[pos]++;
            pos += pos & -pos;
        }
    }
    int prefix_sum(int pos) {
        pos++;
        int ret = 0;
        while (pos > 0) {
            ret += arr[pos];
            pos -= pos & -pos;
        }
        return ret;
    }
    int search(int num) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int key = prefix_sum(mid - 1) + num;
            if (key >= mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        arr.resize(people.size() + 1);
        sort(people.begin(), people.end(),
             [&](vector<int>& x, vector<int>& y) -> bool { return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]); });
        vector<vector<int>> ret(people.size(), vector<int>(2));
        for (auto& p : people) {
            int idx = search(p[1]);
            ret[idx][0] = p[0];
            ret[idx][1] = p[1];
            add(idx);
        }
        return ret;
    }
};
