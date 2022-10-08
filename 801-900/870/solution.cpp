//贪心
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ret(n);
        vector<pair<int, int>> tmp;
        for(int i = 0; i < n; ++i){
            tmp.push_back({nums2[i], i});
        }
        sort(nums1.begin(), nums1.end());
        sort(tmp.begin(), tmp.end());
        int l = 0, r = n - 1;
        for(int i = 0; i < n; ++i){
            if(nums1[i] <= tmp[l].first){
                ret[tmp[r].second] = nums1[i];
                --r;
            } else {
                ret[tmp[l].second] = nums1[i];
                ++l;
            }
        }
        return ret;
    }
};
