//BFS，若s1[i] != s2[i]，则找到所有的i+1 <= j < n使得s2[i] = s1[j]，将s1的i,j元素交换后加入队列
class Solution {
    unordered_set<string> visited;
    queue<pair<string, int>> q;
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.size();
        q.push({s1, 0});
        while(!q.empty()){
            auto [str, step] = q.front();
            q.pop();
            int ptr = 0;
            while(ptr < n){
                if(str[ptr] == s2[ptr]) ++ptr;
                else break;
            }
            if(ptr == n) return step;
            for(int i = ptr + 1; i < n; ++i){
                if(str[i] == s2[ptr]){
                    char temp = str[i]; str[i] = str[ptr]; str[ptr] = temp;
                    if(!visited.count(str)) {
                        visited.insert(str);
                        q.push({str, step + 1});
                    }
                    temp = str[i]; str[i] = str[ptr]; str[ptr] = temp;
                }
            }
        }
        return -1;
    }
};
