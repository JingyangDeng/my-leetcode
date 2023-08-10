//归并排序思想，O(nlogn)
class Solution {
private:
    int get_reverse_pair(vector<int>& nums, int left, int right) {
        if (left + 1 >= right)
            return 0;
        int ret = 0, mid = (left + right + 1) >> 1;
        ret += get_reverse_pair(nums, left, mid);
        ret += get_reverse_pair(nums, mid, right);
        vector<int> tmp1(mid - left);
        vector<int> tmp2(right - mid);
        for (int i = 0; i < mid - left; i++) {
            tmp1[i] = nums[left + i];
        }
        for (int i = 0; i < right - mid; i++) {
            tmp2[i] = nums[mid + i];
        }
        int i = 0, j = 0;
        for (int k = left; k < right; k++) {
            if (j == right - mid) {
                nums[k] = tmp1[i++];
            } else if (i == mid - left || tmp1[i] > tmp2[j]) {
                nums[k] = tmp2[j++];
                ret += (mid - left - i);
            } else {
                nums[k] = tmp1[i++];
            }
        }
        return ret;
    }

public:
    int reversePairs(vector<int>& nums) {
        return get_reverse_pair(nums, 0, nums.size());
    }
};
