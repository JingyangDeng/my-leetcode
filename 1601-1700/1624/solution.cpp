//哈希表记录第一次出现的位置，一次遍历
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ret = -1;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); ++i){
            if(!m.count(s[i])){
                m[s[i]] = i;
            } else {
                ret = max(ret, i - m[s[i]] - 1);
            }
        }
        return ret;
    }
};
