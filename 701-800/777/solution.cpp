//L和R的相对顺序是固定的
//L不能右移，R不能左移
//从两字符串中依次找出非X的字母，看他们是否相等，比较他们的位置即可
class Solution {
public:
    bool canTransform(string start, string end) {
        int p = 0, q = 0;
        int lcnt = 0, rcnt = 0;
        while(p < start.size() && q < end.size()){
            while(p < start.size() && start[p] == 'X') ++p;
            while(q < end.size() && end[q] == 'X') ++q;
            if(p < start.size() ^ q < end.size()) return false;
            if(start[p] != end[q]) return false;
            if(start[p] == 'L' && p < q) return false;
            if(start[p] == 'R' && p > q) return false;
            ++p; ++q;
        }
        while(p < start.size()){
            if(start[p] != 'X') return false;
            ++p;
        }
        while(q < end.size()){
            if(end[q] != 'X') return false;
            ++q;
        }
        return true;
    }
};
