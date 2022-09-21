//哈希表记录每个piece的第一个元素以及该piece在pieces中的下标
//模拟匹配即可
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> id;
        for(int i = 0; i < pieces.size(); ++i){
            id[pieces[i][0]] = i;
        }
        int p = 0;
        while(p < arr.size()){
            if(!id.count(arr[p])) return false;
            int i = id[arr[p]];
            int k = 0;
            while(k < pieces[i].size()){
                if(p >= arr.size() || arr[p] != pieces[i][k]) return false;
                ++p; ++k;
            }
        }
        return true;
    }
};
