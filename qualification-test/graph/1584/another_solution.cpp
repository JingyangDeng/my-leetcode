//kruskal algorithm
class DSU {
public:
    int* parent;
    int* sz;
    DSU(int n){
        parent = new int[n];
        sz = new int[n];
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool u(int x, int y){
        int xr = find(x), yr = find(y);
        if(xr == yr) return false;
        if(sz[xr] < sz[yr]){
            parent[xr] = yr;
            sz[yr] += sz[xr];
        } else {
            parent[yr] = xr;
            sz[xr] += yr;
        }
        return true;
    }
};

class Solution {
private:
    int d(const vector<int>& a, const vector<int>& b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), ret = 0;
        vector<pair<int, int>> dists;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                dists.push_back({d(points[i], points[j]), (i << 10) + j});
            }
        }
        sort(dists.begin(), dists.end());
        DSU* dsu = new DSU(n);
        int cnt = 0;
        for(auto [dist, pos] : dists){
            int i = pos >> 10;
            int j = pos - (i << 10);
            if(dsu->u(i, j)){
                ret += dist;
                ++cnt;
                if(cnt == n-1) break;
            }
        }
        return ret;
    }
};
