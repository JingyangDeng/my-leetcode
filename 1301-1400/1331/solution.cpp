//排序+哈希表
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s;
        for(int a : arr){
            s.emplace(a);
        }
        unordered_map<int, int> ord;
        int i = 0;
        for(int n : s){
            ord[n] = ++i;
        }
        vector<int> ret(arr.size(), 0);
        for(int i = 0; i < arr.size(); ++i){
            ret[i] = ord[arr[i]];
        }
        return ret;
    }
};
