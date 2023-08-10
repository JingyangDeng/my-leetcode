// 考虑利用前i个数所能到达的最远位置。
class Solution {
    public boolean canJump(int[] nums) {
        int far = 0;
        for(int i = 0; i < nums.length; ++i){
            if(far < i) return false;
            far = Math.max(far, i + nums[i]);
        }
        return true;
    }
}

