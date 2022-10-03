//贪心
class Solution {
public:
    int minAddToMakeValid(string s) {
        int curr = 0;
        int cnt = 0;
        for(auto c : s){
            if(c == '(') ++curr;
            else {
                if(!curr) ++cnt;
                else --curr;
            }
        }
        return cnt + curr;
    }
};
