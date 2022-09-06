//模拟
class Solution {
public:
    string reorderSpaces(string text) {
        int n = text.size();
        string ret(n, ' ');
        int space = 0;
        int word = 0;
        for(int i = 0; i < n; ++i){
            if(text[i] == ' ') ++space;
            else {
                if(i == 0 || text[i-1] == ' ') ++word;
            }
        }
        int m = word != 1 ? space / (word - 1) : 0;
        int r = 0, w = 0;
        while(r < n){
            while(r < n && text[r] == ' ') ++r;
            while(r < n && text[r] != ' ') {
                ret[w] = text[r];
                ++w; ++r;
            }
            w += m;
        }
        return ret;
    }
};
