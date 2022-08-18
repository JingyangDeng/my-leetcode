//moore投票
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = -1;
        for(int n : nums){
            if(!cnt){
                candidate = n;
                ++cnt;
                continue;
            }
            if(n == candidate) ++cnt;
            else --cnt;
        }
        return candidate;
    }
};
