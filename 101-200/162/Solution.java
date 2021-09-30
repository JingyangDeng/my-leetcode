//简单地遍历寻找峰值
class Solution {
    public int findPeakElement(int[] nums) {
        boolean f1, f2;
        for(int i = 0; i < nums.length; i++){
            f1 = true; f2 = true;
            try {
                f1 = nums[i] > nums[i+1];
            } catch(IndexOutOfBoundsException e){}
            try {
                f2 = nums[i] > nums[i-1];
            } catch(IndexOutOfBoundsException e){}
            if(f1 && f2) return i;
        }
        return -1;
    }
}
