//简单遍历
class Solution {
public:
    int minPartitions(string n) {
        int ret = 0;
        for (auto c : n) {
            ret = max(ret, c - '0');
        }
        return ret;
    }
};
