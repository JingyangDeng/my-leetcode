class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) return nums;
        int n = nums.size();
        vector<int> res = {};
        //find p where nums[p ... i] is consecutive & ascending
        //cur = nums[p]
        int cur = nums[0], p = 0; 
        for(int i = 1; i < n; ++i) {
            if(nums[i] != cur + i - p) {
                cur = nums[i];
                p = i;
            }
            //if i-k+1 >= p, then nums[i-k+1 ... i] is what we want
            if(i >= k-1) res.emplace_back(i-p >= k-1 ? cur+i-p : -1);
        }
        return res;
    }
};
