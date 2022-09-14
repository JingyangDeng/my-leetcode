// 注意到有意义的按钮只有4个，有意义的操作最多4次，使用位运算穷举求解即可

// 6k, 6k+2 : 1,2  -> 1
// 6k+1 : 1,3,4  -> 0
// 6k+3, 6k+5 : 1,3  -> 2
// 6k+4 : 1,2,4  -> 3

// presses : {0/1, 0/1, 0/1, 0/1}

class Solution {
public:
    int flipLights(int n, int presses) {
        int m = n < 4 ? n : 4;
        vector<int> ops = {15, 10, 5, 9};
        queue<int> q;
        q.push((1 << m) - 1);
        for(int i = 0; i < min(presses, 4); ++i){
            int sz = q.size();
            for(int j = 0; j < sz; ++j){
                int status = q.front();
                q.pop();
                for(int op : ops){
                    int temp = status ^ (op & ((1 << m) - 1));
                    q.push(temp);
                }
            }
        }
        unordered_set<int> s;
        while(!q.empty()){
            s.insert(q.front());
            q.pop();
        }
        return s.size();
    }
};
