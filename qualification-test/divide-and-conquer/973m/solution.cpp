//快速选择
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, int>> v = {};
        vector<vector<int>> ret = {};
        for (int i = 0; i < points.size(); i++) {
            v.emplace_back(make_pair(sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]), i));
        }
        nth_element(v.begin(), v.begin() + k, v.end());
        for (auto it = v.begin(); it != v.begin() + k; it++) {
            ret.emplace_back(points[it->second]);
        }
        return ret;
    }
};
