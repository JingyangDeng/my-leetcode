// O(nΣ+ΣlogΣ)
// 对每个字符求最小“闭包” O(nΣ)，具体地，求出每个字符最左和最右的位置，再根据中间的元素向两边扩充。
// 之后使用贪心法优先安排结束位置靠前的闭包。
struct cmp {
    bool operator()(pair<int, int>& x, pair<int, int>& y) {
        return x.second > y.second;
    };
};

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int, int>> p(26, make_pair(-1, s.size()));
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (p[idx].first == -1) {
                p[idx].first = i;
            }
            p[idx].second = i;
        }
        for (int i = 0; i < 26; i++) {
            if (p[i].first == -1)
                continue;
            int begin = p[i].first, end = p[i].second;
            int lend = end, rbegin = end + 1;
            while (1) {
                int tmp1 = begin, tmp2 = end;
                for (int j = tmp1; j <= lend; j++) {
                    begin = min(p[s[j] - 'a'].first, begin);
                    end = max(p[s[j] - 'a'].second, end);
                }
                for (int j = rbegin; j <= tmp2; j++) {
                    begin = min(p[s[j] - 'a'].first, begin);
                    end = max(p[s[j] - 'a'].second, end);
                }
                lend = tmp1 - 1;
                rbegin = tmp2 + 1;
                if (begin == tmp1 && end == tmp2)
                    break;
            }
            q.emplace(begin, end);
        }
        vector<string> ret;
        int last = -1;
        while (!q.empty()) {
            auto [b, e] = q.top();
            q.pop();
            if (b > last) {
                last = e;
                ret.emplace_back(s.substr(b, e - b + 1));
            }
        }
        return ret;
    }
};
