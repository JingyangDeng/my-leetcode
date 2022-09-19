//状压+DFS+记忆化搜索
//考虑一个一个往当前子集添加数的过程，当前子集和==target时继续构造下一个子集
//使用一个n bit的整数status记录还有哪些数没有被添加

//需要注意到对于给定的status,不论已经构造好的子集的具体构造方式如何，当前子集之和curr都是一样的，并且都一定对应唯一的true/false结果
//这为记忆化搜索提供了基础
class Solution {
    vector<int> dp;
    int n, target = 0;
    int dfs(vector<int>& nums, int status, int curr){
        if(!status) return 1;
        if(!dp[status]) return 0;
        for(int i = 0; i < n; ++i){
            if(curr + nums[i] > target) continue;
            if(status & (1 << i)){
                if(dfs(nums, status ^ (1 << i), (curr + nums[i]) % target)) return 1;
            }
        }
        return dp[status] = 0;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        for(int n : nums) target += n;
        if(target % k) return false;
        target /= k;
        sort(nums.begin(), nums.end());
        if(nums.back() > target) return false;
        dp = vector<int>(1 << n, 1);
        return dfs(nums, (1 << n) - 1, 0);
    }
};
