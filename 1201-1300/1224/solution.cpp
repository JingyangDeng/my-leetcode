//哈希表，要点在于不仅要设置cnt统计元素的分布情况，还要设置freq统计元素出现次数的分布情况
//这样才能在O(n)时间复杂度内完成
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, int> freq;
        int max_cnt = 0;
        int ret = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(cnt[nums[i]]) --freq[cnt[nums[i]]];
            ++cnt[nums[i]];
            ++freq[cnt[nums[i]]];
            max_cnt = max(max_cnt, cnt[nums[i]]);
            if(max_cnt == 1) {
                ret = max(ret, i + 1);
                continue;
            }
            if(freq[max_cnt-1] * (max_cnt-1) + max_cnt == i+1 && freq[max_cnt] == 1){
                ret = max(ret, i + 1);
                continue;
            }
            if(freq[max_cnt] * max_cnt == i && freq[1] == 1){
                ret = max(ret, i + 1);
                continue;
            }
        }
        return ret;
    }
};
