//归并排序
class Solution {
    void mergeSort(vector<int>& nums, int left, int right){
        if(left + 1 >= right) return;
        int mid = (left + right) >> 1;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid, right);
        vector<int> tmp(right - left);
        int p = 0, p1 = left, p2 = mid;
        while(p1 < mid || p2 < right){
            if(p1 == mid){
                tmp[p++] = nums[p2++];
            } else if(p2 == right){
                tmp[p++] = nums[p1++];
            } else {
                if(nums[p1] <= nums[p2]){
                    tmp[p++] = nums[p1++];
                } else {
                    tmp[p++] = nums[p2++];
                }
            }
        }
        for(int i = 0; i < right - left; ++i){
            nums[left + i] = tmp[i];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size());
        return nums;
    }
};
