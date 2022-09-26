//哈希表
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char, int> cnt;
        for(char c : s1) ++cnt[c];
        for(char c : s2) --cnt[c];
        for(auto [k, v] : cnt) if(v) return false;
        return true;
    }
};
