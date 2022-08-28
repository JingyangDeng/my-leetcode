//一次遍历
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret(n << 1);
        for(int i = 0; i < (n << 1); ++i){
            if(i & 1) ret[i] = nums[n + (i >> 1)];
            else ret[i] = nums[i >> 1];
        }
        return ret;
    }
};
