//双连通分量
class Solution {
    vector<vector<int>> ret;
    vector<vector<int>> adj;
    vector<int> discover;
    vector<int> color;
    stack<pair<int, int>> st;
    int time = 0;
    
    int back(int v, int parent){
        discover[v] = ++time;
        color[v] = 1;
        int vback = discover[v];
        for(int w : adj[v]){
            if(color[w] == 0){
                st.push({v, w});
                int wback = back(w, v);
                if(wback >= discover[v]){
                    vector<int> temp(2);
                    int cnt = 0;
                    while(!st.empty()){
                        auto [vv, ww] = st.top(); st.pop();
                        ++cnt;
                        temp[0] = vv; temp[1] = ww;
                        if(vv == v && ww == w) break;
                    }
                    if(cnt == 1){
                        ret.push_back(temp);
                    }
                } else vback = min(vback, wback);
            } else if(color[w] == 1 && w != parent){
                st.push({v, w});
                vback = min(vback, discover[w]);
            }
        }
        color[v] = 2;
        return vback;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj = vector<vector<int>>(n, vector<int>());
        color = vector<int>(n, 0);
        discover = vector<int>(n, -1);
        for(auto& conn : connections){
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        for(int v = 0; v < n; ++v){
            if(color[v] == 0){
                back(v, -1);
            }
        }
        return ret;
    }
};
