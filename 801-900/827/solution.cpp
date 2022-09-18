//并查集
class DSU {
public:
    vector<int> parent;
    vector<int> sz;
    DSU(int n){
        parent.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; ++i){
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void u(int x, int y){
        int xr = find(x), yr = find(y);
        if(xr == yr) return;
        if(sz[xr] < sz[yr]){
            parent[xr] = yr;
            sz[yr] += sz[xr];
        } else {
            parent[yr] = xr;
            sz[xr] += sz[yr];
        }
    }
};

class Solution {
    int n;
    DSU* dsu;
    void connect(vector<vector<int>>& grid, int i, int j){
        if(i > 0 && grid[i-1][j]) dsu->u(i*n+j, (i-1)*n+j);
        if(i < n-1 && grid[i+1][j]) dsu->u(i*n+j, (i+1)*n+j);
        if(j > 0 && grid[i][j-1]) dsu->u(i*n+j, i*n+j-1);
        if(j < n-1 && grid[i][j+1]) dsu->u(i*n+j, i*n+j+1);
    }

    int area(vector<vector<int>>& grid, int i, int j){
        unordered_set<int> s;
        int ret = 1;
        if(i > 0 && grid[i-1][j]) s.insert(dsu->find((i-1)*n+j));
        if(i < n-1 && grid[i+1][j]) s.insert(dsu->find((i+1)*n+j));
        if(j > 0 && grid[i][j-1]) s.insert(dsu->find(i*n+j-1));
        if(j < n-1 && grid[i][j+1]) s.insert(dsu->find(i*n+j+1));
        for(int r : s) ret += dsu->sz[r];
        return ret;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        dsu = new DSU(n*n);
        int ret = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]) connect(grid, i, j);
            }
        }
        for(int i = 0; i < n*n; ++i){
            ret = max(ret, dsu->sz[i]);
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]) continue;
                ret = max(ret, area(grid, i, j));
            }
        }
        return ret;
    }
};
