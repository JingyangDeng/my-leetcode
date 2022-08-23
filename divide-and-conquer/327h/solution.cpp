//可将题目转化为前缀和之差的形式
//在归并排序的框架下分治完成
class Solution {
    vector<long long> cum_sum;
    void cumSum(vector<int>& nums){
        long long tmp = 0;
        for(int i = 0; i < nums.size(); ++i){
            tmp += nums[i];
            cum_sum[i] = tmp;
        }
    }
    int mergeCountRangeSum(int lower, int upper, int left, int right){
        if(left + 1 == right){
            return cum_sum[left] >= lower && cum_sum[left] <= upper;
        }
        int mid = (left + right) >> 1;
        int ret = mergeCountRangeSum(lower, upper, left, mid) + mergeCountRangeSum(lower, upper, mid, right);
        
        //对给定的lptr1用双指针维护区间[rptr1, rptr2)，复杂度为O(n)，进而总时间复杂度为O(nlogn)
        int lptr1 = left, rptr1 = mid, rptr2 = mid;
        while(lptr1 < mid && rptr1 < right){
            if(cum_sum[rptr1] - cum_sum[lptr1] < lower) {
                ++rptr1;
                continue;
            }
            while(rptr2 < right && cum_sum[rptr2] - cum_sum[lptr1] <= upper){
                ++rptr2;
            }
            ret += rptr2 - rptr1;
            ++lptr1;
        }
        
        //merge sort
        vector<long long> tmp(right - left);
        int ptr = 0;
        int lptr = left, rptr = mid;
        while(lptr < mid || rptr < right){
            if(lptr == mid){
                tmp[ptr] = cum_sum[rptr];
                ++ptr; ++rptr;
            } else if(rptr == right){
                tmp[ptr] = cum_sum[lptr];
                ++ptr; ++lptr;
            } else {
                if(cum_sum[lptr] <= cum_sum[rptr]){
                    tmp[ptr] = cum_sum[lptr];
                    ++ptr; ++lptr;
                } else {
                    tmp[ptr] = cum_sum[rptr];
                    ++ptr; ++rptr;
                }
            }
        }
        for(int i = 0; i < right - left; ++i){
            cum_sum[i + left] = tmp[i];
        }
        return ret;
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        cum_sum = vector<long long>(nums.size());
        cumSum(nums);
        return mergeCountRangeSum(lower, upper, 0, nums.size());
    }
};
