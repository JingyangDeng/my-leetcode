//可以证明当k>2时可实现对换操作，进而可获得任一字符串
//当k=1时穷举最小可能
class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ret = s;
        if(k == 1){
            for(int i = 0; i < s.size(); ++i){
                char c = s[0];
                s = s.substr(1);
                s.push_back(c);
                if(s < ret) ret = s;
            }
        } else {
            sort(s.begin(), s.end());
            ret = s;
        }
        return ret;
    }
};
