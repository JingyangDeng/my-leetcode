//注意当某位置i不为峰值，但有nums[i] > nums[i-1]时，一定存在峰值j > i
//相反，若有nums[i] < nums[i-1]，则一定存在峰值j < i
//故可使用二分法进行查找
class OptimalSolution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length-1, mid;
        boolean f1, f2;
        while(l < r){
            mid = (l + r) >> 1;

            try{
                f1 = nums[mid] > nums[mid-1];
            } catch(IndexOutOfBoundsException e){
                f1 = true;   
            }

            f2 = nums[mid] > nums[mid+1];

            if(f1 && f2) return mid;

            if(f1) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
}
