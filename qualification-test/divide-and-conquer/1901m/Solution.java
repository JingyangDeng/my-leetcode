//Mark:
//对行（或列）二分，分别找到相邻三行的最大值lmax, mmax, rmax，若mmax最大，
//则返回中间行最大值的坐标，否则继续查找
//若lmax > rmax向上查找，否则向下查找
//复杂度O(mlogn)或O(nlogm)
class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int l = 0, r = m-1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int lmax = -1, rmax = -1;
            try{
                lmax = max(mat[mid-1]);
            } catch(IndexOutOfBoundsException e){}
            try{
                rmax = max(mat[mid+1]);
            } catch(IndexOutOfBoundsException e){}
            int mmax = max(mat[mid]);
            if(mmax >= lmax && mmax >= rmax){
                int[] ret = {mid, find(mat[mid], mmax)};
                return ret;
            }
            if(lmax > rmax){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return new int[2];
    }

    private int find(int[] nums, int target){
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == target) return i;
        }
        return -1;
    }

    private int max(int[] nums){
        int max = -1;
        for(int i = 0; i < nums.length; i++){
            max = Math.max(max, nums[i]);
        }
        return max;
    }
}
