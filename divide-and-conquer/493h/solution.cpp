//归并排序，合并时需进行额外的O(n)统计两区间之间的反转对数量
class Solution {
private:
    int merge(vector<int>& nums, int left, int right) {
        if (left + 1 == right)
            return 0;
        int ret = 0;
        int mid = (left + right + 1) >> 1;
        ret += merge(nums, left, mid);
        ret += merge(nums, mid, right);

        vector<int> tmp(right - left);
        int p = left, q = mid, r = left, k = 0;
        while (p < mid || q < right) {
            if (q == right) {
                tmp[k++] = nums[p++];
            } else if (p == mid || nums[q] < nums[p]) {
                while (r < mid && nums[r] <= 2 * (long long)nums[q])
                    r++;
                ret += (mid - r);
                tmp[k++] = nums[q++];
            } else {
                tmp[k++] = nums[p++];
            }
        }
        for (int i = 0; i < right - left; i++) {
            nums[left + i] = tmp[i];
        }
        return ret;
    }

public:
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size());
    }
};
