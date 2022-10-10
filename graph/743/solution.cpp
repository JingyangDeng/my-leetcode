//dijkstra algorithm
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ret = 0;
        vector<vector<int>> adjm(n, vector<int>(n, INT_MAX));
        vector<vector<int>> dij(n, vector<int>(2));
        for(auto& t : times){
            int u = t[0]-1, v = t[1]-1;
            adjm[u][v] = t[2];
        }
        for(int i = 0; i < n; ++i) {
            if(i != k - 1){
                if(adjm[k-1][i] < INT_MAX){
                    dij[i][0] = adjm[k-1][i];
                    dij[i][1] = i;
                } else {
                    dij[i][0] = INT_MAX;
                    dij[i][1] = -1;
                }
                adjm[i][i] = 0;
            } else {
                dij[i][0] = 0;
                dij[i][1] = k-1;
                adjm[i][i] = 1;
            } 
        }
        for(int i = 1; i < n; ++i){
            int cur = INT_MAX;
            int w = -1;
            for(int j = 0; j < n; ++j){
                if(adjm[j][j] == 0 && dij[j][0] < cur){
                    cur = dij[j][0];
                    w = j;
                }
            }
            if(w == -1) return -1;
            adjm[w][w] = 1;
            for(int j = 0; j < n; ++j){
                if(adjm[j][j] == 0 && adjm[w][j] < INT_MAX && dij[j][0] > dij[w][0] + adjm[w][j]){
                    dij[j][0] = dij[w][0] + adjm[w][j];
                    dij[j][1] = w;
                }
            }
            
        }
        for(int i = 0; i < n; ++i){
            ret = max(ret, dij[i][0]);
        }
        return ret;
    }
};
