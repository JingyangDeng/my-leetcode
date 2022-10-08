//递归计算
//注：该题有O(n)的算法
class Solution {
public:
    int scoreOfParentheses(string s) {
        if(s == "()") return 1;
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '(') ++cnt;
            else --cnt;
            if(cnt == 0){
                if(i == n - 1) return 2 * scoreOfParentheses(s.substr(1, n - 2));
                else return scoreOfParentheses(s.substr(0, i + 1)) + scoreOfParentheses(s.substr(i + 1, n - i - 1));
            }
        }
        return -1;
    }
};
