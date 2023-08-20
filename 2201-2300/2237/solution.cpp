//双指针，依次对比LR的相对位置
class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        while(1) {
            while(i < start.size() && start[i] == '_') ++i;
            while(j < target.size() && target[j] == '_') ++j;
            if(i == start.size() && j == target.size()) break;
            if(i == start.size() || j == target.size()) return false;
            if(start[i] != target[j]) return false;
            if(start[i] == 'L' && i < j) return false;
            if(start[i] == 'R' && i > j) return false;
            ++i; ++j;
        }
        return true;
    }
};
