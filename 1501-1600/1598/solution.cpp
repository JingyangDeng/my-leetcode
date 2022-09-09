//计数器模拟
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ret = 0;
        for(auto& log : logs){
            if(log == "./") continue;
            if(log == "../"){
                if(!ret) continue;
                --ret;
            } else ++ret;
        }
        return ret;
    }
};
