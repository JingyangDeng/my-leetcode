//在该题中，元素数>1的强连通分量一定是环，复杂度O(n)
class Solution {
    void invdfs(const vector<vector<int>>& invadj, int v, vector<int>& color, stack<int>& st){
        color[v] = 1;
        for(int w : invadj[v]){
            if(color[w] == 0){
                invdfs(invadj, w, color, st);
            }
        }
        color[v] = 2;
        st.push(v);
    }
    void dfs(const vector<vector<int>>& adj, int v, vector<int>& color, vector<int>& scc){
        color[v] = 1;
        scc.push_back(v);
        for(int w : adj[v]){
            if(color[w] == 0){
                dfs(adj, w, color, scc);
            }
        }
        color[v] = 2;
    }

    bool getCircuit(const vector<vector<int>>& adj, const vector<vector<int>>& invadj, vector<int>& scc){
        int n = adj.size()-1;
        vector<int> color(n+1, 0);
        stack<int> st;
        for(int i = 1; i <= n; ++i){
            if(color[i] == 0) invdfs(invadj, i, color, st);
        }

        for(int i = 1; i <= n; ++i) color[i] = 0;
        while(!st.empty()){
            int v = st.top(); st.pop();
            if(color[v] == 0) {
                scc.clear();
                dfs(adj, v, color, scc);
                if(scc.size() > 1) return true;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1, vector<int>());
        vector<vector<int>> invadj(n+1, vector<int>());
        int vmax = -1;
        for(auto& e : edges){
            int v = e[0], w = e[1];
            adj[v].push_back(w);
            invadj[w].push_back(v);
            if(invadj[w].size() > 1) {
                vmax = w;
            }
        }

        //所有点入度均为1,则必有环路，求出该>1的强连通分量
        if(vmax == -1){
            vector<int> scc;
            getCircuit(adj, invadj, scc);
            unordered_set<int> s;
            for(int i = 0; i < scc.size(); ++i){
                int j = (i + 1) % scc.size();
                s.insert((scc[i] << 10) + scc[j]);
            }
            //找到环在edges中最后出现的边返回
            for(int i = n-1; i >= 0; --i){
                if(s.count((edges[i][0] << 10) + edges[i][1])) return edges[i];
            }
        }
        
        vector<int> scc;
        //若存在入度为2的点，且无回路=>多余的边是交叉边/向前边
        if(!getCircuit(adj, invadj, scc)) return {invadj[vmax].back(), vmax};

        //若有回路，删掉回路中的是节点入度为2的边
        unordered_set<int> s;
        for(int i = 0; i < scc.size(); ++i){
            int j = (i + 1) % scc.size();
            s.insert((scc[i] << 10) + scc[j]);
        }
        for(int i = invadj[vmax].size()-1; i >= 0; --i){
            int w = invadj[vmax][i];
            if(s.count((w << 10) + vmax)) return {w, vmax};
        }

        return vector<int>();
    }
};
