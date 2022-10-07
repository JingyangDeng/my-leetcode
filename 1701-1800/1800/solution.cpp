//双指针
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = start + 1;
        int ret = 0;
        while(start < n){
            int curr = nums[start];
            while(end < n && nums[end] > nums[end - 1]){
                curr += nums[end];
                ++end;
            }
            ret = max(ret, curr);
            start = end;
            end = start + 1;
        }
        return ret;
    }
};
