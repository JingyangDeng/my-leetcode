// 使用栈一次遍历，也可使用双指针在原地修改字符串
class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i] >= 65 && s[i] <= 90) || s[i] >= 97) {
                st.push(s[i]);
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i] >= 65 && s[i] <= 90) || s[i] >= 97) {
                s[i] = st.top();
                st.pop();
            }
        }
        return s;
    }
};
