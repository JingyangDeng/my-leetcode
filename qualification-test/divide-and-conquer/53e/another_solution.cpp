//分治法求解
struct Info {
    int lsum, rsum, isum, msum;
};

class Solution {
    Info get(const vector<int>& nums, int left, int right) {
        if (left + 1 == right)
            return (Info){nums[left], nums[left], nums[left], nums[left]};
        int mid = (left + right) >> 1;
        Info l_info = get(nums, left, mid);
        Info r_info = get(nums, mid, right);
        int isum = l_info.isum + r_info.isum;
        int lsum = max(l_info.lsum, l_info.isum + r_info.lsum);
        int rsum = max(r_info.rsum, r_info.isum + l_info.rsum);
        int msum = max(max(l_info.msum, r_info.msum), l_info.rsum + r_info.lsum);
        return (Info){lsum, rsum, isum, msum};
    }

public:
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size()).msum;
    }
};
