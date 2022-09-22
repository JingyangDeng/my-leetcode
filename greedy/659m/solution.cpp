//贪心，每次构造一个数组，从当前最小数a[min]开始，直到cnt[min+i-1] > cnt[min+i]
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        map<int, int> cnt;
        for(int i = 0; i < n; ++i) ++cnt[nums[i]];
        int complete = 0;
        while(complete < n){
            auto [k, v] = *cnt.begin();
            int j = 1;
            while(cnt.count(k + j) && cnt[k + j - 1] <= cnt[k + j]) ++j;
            if(j < 3) return false;
            for(int i = k; i < k + j; ++i){
                --cnt[i];
                if(!cnt[i]) cnt.erase(i);
                ++complete;
            }
        }
        return true;
    }
};
