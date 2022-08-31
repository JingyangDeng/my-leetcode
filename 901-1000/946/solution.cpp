//模拟
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int p1 = 0, p2 = 0;
        stack<int> st;
        while(p1 < pushed.size()){
            st.push(pushed[p1]); ++p1;
            while(!st.empty() && st.top() == popped[p2]){
                st.pop(); ++p2;
            }
        }
        return st.empty();
    }
};
