//维护有序集合
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s = {};
        for (int n : nums) {
            s.insert(n);
            if (s.size() > 3)
                s.erase(s.begin());
        }
        return s.size() < 3 ? *(s.rbegin()) : *(s.begin());
    }
};
