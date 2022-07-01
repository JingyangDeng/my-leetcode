//记忆化搜索
//执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//内存消耗：6.6 MB, 在所有 C++ 提交中击败了88.70% 的用户
class Solution {
    unordered_map<int, vector<int>> buf;
    vector<int> nums;
    vector<int> ops;

public:
    vector<int> diffWaysToCompute(string expression) {
       int p = 0;
       while(p < expression.size()){
           char c = expression[p];
           if(c == '+' || c == '*' || c == '-'){
               ops.push_back(c);
               ++p;
               continue;
           }
           int num = 0;
           while(p < expression.size() && '0' <= expression[p] && expression[p] <= '9'){
               num *= 10;
               num += expression[p] - '0';
               ++p;
           }
           nums.push_back(num);
       }
       gen_res_list(0, nums.size());
       return buf[nums.size()];
    }

    void gen_res_list(int begin, int end){
        int idx = (begin << 10) + end;
        if(buf.count(idx)) return;
        if(begin == end - 1){
            buf[idx].push_back(nums[begin]);
            return;
        }
        for(int mid = begin + 1; mid < end; ++mid){
            gen_res_list(begin, mid);
            gen_res_list(mid, end);
            vector<int>& res1 = buf[(begin << 10) + mid];
            vector<int>& res2 = buf[(mid << 10) + end];
            for(int r1 : res1){
                for(int r2 : res2){
                    if(ops[mid-1] == '+'){
                        buf[idx].push_back(r1 + r2);
                    } else if(ops[mid-1] == '-'){
                        buf[idx].push_back(r1 - r2);
                    } else {
                        buf[idx].push_back(r1 * r2);
                    }
                }
            }
        }
        return;
    }

};
