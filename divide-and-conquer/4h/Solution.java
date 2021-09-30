//思想很简单，固定和的双指针(p+q = (m+n-1) >> 1)，二分查找
//若nums1[p] < num2[q]，说明nums2[q]至少大于(m+n+1)>>1个数
//复杂度O(log(min(m, n)))
//但最后的边界判断和逻辑判断很复杂！应该是可以优化的。
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        if(m == 0){
            if((n & 1) == 0){
                return (nums2[(n - 1) >> 1] + nums2[n >> 1]) * .5;
            }
            return (double)nums2[(n - 1) >> 1];
        }
        int s = (m + n - 1) >> 1;
        int l = 0, r = m-1;
        while(l < r){
            int p = (l + r) >> 1;
            int q = s - p;
            if(nums1[p] == nums2[q]) return nums1[p];
            if(nums1[p] < nums2[q]) l = p+1;
            else r = p;
        }
        //System.out.println(l);
        if(((m + n) & 1) == 0){
            if(l == 0) {
                if(nums1[l] < nums2[s]) {
                    if(s > l) return (Math.max(nums1[l], nums2[s-1]) + nums2[s]) * .5;
                    return (nums1[l] + nums2[s]) * .5;
                }
                if(s == n-1) return (nums2[s] + nums1[l]) * .5;
                return (nums2[s] + Math.min(nums2[s+1], nums1[l])) * .5;
            }
            if(l == m-1 && nums1[l] < nums2[s-l]) {
                if(s > l) return (nums2[s-l] + Math.max(nums1[l], nums2[s-l-1])) * .5;
                return (nums2[s-l] + nums1[l]) * .5;
            }
            return (Math.max(nums1[l-1], nums2[s-l]) + Math.min(nums2[s-l+1], nums1[l])) * .5;
        }
        if(l == 0) {
            if(nums1[l] < nums2[s]) {
                if(s > l) return (double)Math.max(nums1[l], nums2[s-1]);
                return (double)nums1[l];
            }
            return (double)nums2[s-l];
        }
        if(l == m-1 && nums1[l] < nums2[s-l]) {
            if(s > l) return (double)Math.max(nums1[l], nums2[s-l-1]);
            return (double)nums1[l];
        }
        return (double)Math.max(nums1[l-1], nums2[s-l]);
    }
}
