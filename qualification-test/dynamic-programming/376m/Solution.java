//考虑前i个数能组成的最长摆动序列的长度
//摆动序列分最后上升(up)和最后下降(down)两类来考虑
class Solution {
    public int wiggleMaxLength(int[] nums) {
        int up = 1, down = 1;
        for(int i = 1; i < nums.length; i++){
            if(nums[i] > nums[i - 1]){
                //来了个更大的数，up的长度不会变，down的长度一定能+1
                up = Math.max(up, down + 1);
            } else if(nums[i] < nums[i - 1]){
                down = Math.max(down, up + 1);
            }
        }
        return Math.max(up, down);
    }
}

