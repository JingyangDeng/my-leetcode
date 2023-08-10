//双连通分量
class Solution {
    vector<vector<int>> adj;
    vector<int> color;
    vector<int> discover;
    vector<int> cut;
    stack<pair<int, int>> st;
    vector<unordered_set<int>> dcc;
    int time = 0;

    int getDCC(int v, int parent){
        color[v] = 1;
        discover[v] = ++time;
        int vback = discover[v];
        int cnt = 0;
        for(int w : adj[v]){
            if(color[w] == 0){
                st.push({v, w});
                int wback = getDCC(w, v);
                if(wback >= discover[v]){
                    ++cnt;
                    //若v不为根且存在wback>=discover[v]，则为割点
                    if(parent != -1) cut[v] = 1;
                    //求点双连通分量
                    unordered_set<int> s;
                    while(!st.empty()){
                        auto [vv, ww] = st.top(); st.pop();
                        s.insert(vv); s.insert(ww);
                        if(vv == v && ww == w) break;
                    }
                    dcc.emplace_back(s);
                } else vback = min(vback, wback);
            } else if(color[w] == 1 && w != parent){
                st.push({v, w});
                vback = min(vback, discover[w]);
            }
        }
        //若v为根但有>1颗子树，则根也为割点
        if(cnt > 1) cut[v] = 1;
        color[v] = 2;
        return vback;
    }
public:
    long long minimumCost(vector<int>& cost, vector<vector<int>>& roads) {
        int n = cost.size();
        adj = vector<vector<int>>(n, vector<int>());
        color = vector<int>(n, 0);
        discover = vector<int>(n, -1);
        cut = vector<int>(n, 0);
        for(auto& r : roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        for(int v = 0; v < n; ++v){
            if(color[v] == 0) getDCC(v, -1);
        }
        
        //若为双连通图，则占领cost最小的一处据点即可
        if(dcc.size() == 1){
            return *min_element(cost.begin(), cost.end());
        }

        //缩图，对每个为叶节点的点双，找出它的非割点的最小cost
        vector<int> temp;
        for(auto& s : dcc){
            int c = INT_MAX;
            int cnt = 0;
            for(int x : s){
                if(!cut[x]) c = min(c, cost[x]);
                else ++cnt;
            }
            if(cnt == 1) temp.push_back(c);
        }
        //对k个叶节点的最小cost，找出其中k-1个最小的占领
        sort(temp.begin(), temp.end());
        long long ret = 0;
        for(int i = 0; i < temp.size()-1; ++i) ret += (long long)temp[i];
        return ret;
    }
};
