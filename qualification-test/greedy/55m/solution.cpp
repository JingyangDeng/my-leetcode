//注意到若一个点是可达的，那么它左边的点都是可达的。
//这样便可以使用贪心法求解，维护当前能到的最远位置。
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_len = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (max_len < i)
                return false;
            max_len = max(max_len, nums[i] + i);
        }
        return max_len >= nums.size() - 1;
    }
};
