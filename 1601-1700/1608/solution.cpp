//对数组降序排列，注意到特征为i+1则必须满足nums[i] >= i + 1 且 nums[i + 1] < i + 1
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y)->bool {
            return x > y;
        });
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if (nums[i] >= i + 1 && (i == n - 1 || nums[i + 1] < i + 1)) {
                return i + 1;
            }
        }
        return -1;
    }
};
