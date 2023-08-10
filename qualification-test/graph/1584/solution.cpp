//prim algorithm
class Solution {
private:
    int d(const vector<int>& a, const vector<int>& b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ret = 0;
        int n = points.size(), iter = n;
        vector<int> flag(n, 0);
        vector<int> dist(n, INT_MAX);
        flag[0] = 1;
        dist[0] = 0;
        for(int i = 1; i < n; ++i){
            dist[i] = d(points[0], points[i]);
        }
        while(--iter){
            for(int i = 0; i < n; ++i){
                if(!flag[i] && (v == -1 || dist[i] < cur)){
                    cur = dist[i];
                    v = i;
                }
            }
            ret += dist[v];
            flag[v] = 1;
            for(int i = 0; i < n; ++i){
                if(!flag[i]){
                    int div = d(points[v], points[i]);
                    if(div < dist[i]) dist[i] = div;
                }
            }
        }
        return ret;
    }
};
