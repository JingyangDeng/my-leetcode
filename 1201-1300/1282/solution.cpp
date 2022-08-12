//简单模拟
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> group;
        vector<vector<int>> ret;
        for(int i = 0; i < groupSizes.size(); ++i){
            int sz = groupSizes[i];
            group[sz].emplace_back(i);
            if(group[sz].size() == sz) {
                ret.emplace_back(group[sz]);
                group[sz].clear();
            }
        }
        return ret;
    }
};
