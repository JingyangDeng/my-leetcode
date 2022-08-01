//直接构造
class Solution {
public:
    string generateTheString(int n) {
        string ret = "";
        if(n % 2){
            for(int i = 0; i < n; ++i) ret.append("a");
        } else {
            for(int i = 0; i < n-1; ++i) ret.append("a");
            ret.append("b");
        }
        return ret;
    }
};
