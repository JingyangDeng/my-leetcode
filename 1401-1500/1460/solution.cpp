//只要两个数组的元素及相应数量相同即可实现操作
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> cnt;
        for(int i = 0; i < target.size(); ++i){
            ++cnt[arr[i]];
            --cnt[target[i]];
        }
        for(auto [k, v] : cnt){
            if(v) return false;
        }
        return true;
    }
};
