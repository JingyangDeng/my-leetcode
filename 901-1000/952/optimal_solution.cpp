// 并查集，设置max(nums)个节点
// 如果i是n的因数，则i和n/i都与n连通
class DSU {
public:
    vector<int> parent;
    vector<int> level;
    DSU(int n){
        parent.resize(n, 0);
        level.resize(n, 0);
        for(int i = 0; i < n; ++i){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void u(int x, int y){
        int xr = find(x);
        int yr = find(y);
        if(xr != yr){
            if(level[xr] < level[yr]){
                parent[xr] = yr;
            } else if(level[xr] > level[yr]) {
                parent[yr] = xr;
            } else {
                parent[xr] = yr;
                ++level[yr];
            }
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        DSU* dsu = new DSU(m + 1);
        for(int i : nums){
            for(int j = 2; j * j <= i; ++j){
                if(i % j == 0){
                    dsu->u(i, j);
                    dsu->u(i, i/j);
                }
            }
        }
        int ret = 0;
        unordered_map<int, int> cnt;
        for(int i : nums){
            int r = dsu->find(i);
            ++cnt[r];
            ret = max(ret, cnt[r]);
        }
        return ret;
    }
};
