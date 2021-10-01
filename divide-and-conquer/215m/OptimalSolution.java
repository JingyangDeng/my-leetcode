//基于快速排序的选择算法，平均时间复杂度为O(n)
//当pivot的索引正好为n-k时，返回nums[k]，否则可递归地对一边进行排序
class Solution {
    private Random r = new Random();
    private int n;

    private void swap(int[] nums, int i, int j){
        int tmp = nums[i]; nums[i] = nums[j]; nums[j] = tmp;
    }

    private int quickSortStep(int[] nums, int left, int right){
        if(left == right-1) return left;
        int p = r.nextInt(right - left) + left;
        int rp = right;
        swap(nums, p, --rp);
        for(int i = left; i < rp; i++){
            while(nums[i] > nums[right-1]) {
                if(i >= rp) break;
                swap(nums, i, --rp);
            }
        }
        swap(nums, rp, right-1);
        return rp;
    }

    public int findKthLargest(int[] nums, int k) {
        n = nums.length;
        int left = 0, right = n, index;
        while(true){
            index = quickSortStep(nums, left, right);
            if(index == n-k) break;
            if(index > n-k) right = index;
            else left = index+1;
        }
        return nums[index];
    }
}
