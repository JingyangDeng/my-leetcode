//将数字转换为字符串，双循环枚举
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int ret = num;
        int n = str.size();
        for(int i = 0; i < n-1; ++i){
            for(int j = i+1; j < n; ++j){
                char temp = str[i]; str[i] = str[j]; str[j] = temp;
                ret = max(ret, stoi(str));
                temp = str[i]; str[i] = str[j]; str[j] = temp;
            }
        }
        return ret;
    }
};
