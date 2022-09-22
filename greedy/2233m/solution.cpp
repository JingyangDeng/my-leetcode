//均值不等式，每次使最小数+1，O(nlogn)
//初始建堆可优化至O(n)，进而总复杂度可优化至O(n + klogn)
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int n : nums){
            q.push(n);
        }
        for(int i = 0; i < k; ++i){
            int n = q.top();
            q.pop();
            q.push(n + 1);
        }
        long long ret = 1;
        while(!q.empty()){
            ret *= q.top();
            ret %= (int)(1e9 + 7);
            q.pop();
        }
        return ret;
    }
};
