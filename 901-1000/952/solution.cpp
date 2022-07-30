// 并查集，设置虚拟质数节点，对每个nums中的元素分解质因数
// TLE
class DSU {
public:
    vector<int> parent;
    vector<int> sz;
    DSU(int n, int v){
        parent.resize(n + v, 0);
        sz.resize(n + v, 0);
        for(int i = 0; i < n+v; ++i){
            parent[i] = i;
            if(i < n) sz[i] = 1;
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
            if(sz[xr] < sz[yr]){
                parent[xr] = yr;
                sz[yr] += sz[xr];
            } else {
                parent[yr] = xr;
                sz[xr] += sz[yr];
            }
        }
    }
};

class Solution {
public:
    vector<int> primes;

    void get_primes(int upper){
        primes.clear();
        primes.emplace_back(2);
        primes.emplace_back(3);
        for(int i = 5; i <= upper; i += 2){
            int j = 1, flag = 1;
            while(j < primes.size() && primes[j] * primes[j] <= i){
                if(i % primes[j] == 0) {
                    flag = 0; break;
                }
                ++j;
            }
            if(flag){
                primes.emplace_back(i);
            }
        }
    }

    int largestComponentSize(vector<int>& nums) {
        get_primes(100000);
        int v = primes.size();
        int n = nums.size();
        DSU* dsu = new DSU(n, v);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < v && primes[j] <= nums[i]; ++j){
                if(nums[i] % primes[j] == 0){
                    dsu->u(i, n + j);
                    while(nums[i] % primes[j] == 0){
                        nums[i] /= primes[j];
                    }
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < dsu->sz.size(); ++i){
            ret = max(ret, dsu->sz[i]);
        }
        return ret;
    }
};
