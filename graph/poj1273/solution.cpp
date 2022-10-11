#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<cmath>
using namespace std;

int maxFlow(const vector<vector<int>>& adjm, int src, int dest) {
    int m = adjm.size() - 1;
    vector<vector<int>> flow(m+1, vector<int>(m+1, 0));
    int ret = 0;
    
    while(1){
        //BFS寻找增流路径
        queue<int> q;
        q.push(src);
        vector<int> delta(m+1, 0);
        delta[src] = INT_MAX;
        vector<int> pre(m+1, 0);
        pre[src] = INT_MAX;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int w = 1; w <= m; ++w){
                if(pre[w]) continue;
                if(adjm[v][w] > 0 && flow[v][w] < adjm[v][w]){
                    pre[w] = v;
                    delta[w] = min(adjm[v][w] - flow[v][w], delta[v]);
                    q.push(w);
                } else if(adjm[w][v] > 0 && flow[w][v] > 0){
                    pre[w] = -v;
                    delta[w] = min(flow[w][v], delta[v]);
                    q.push(w);
                }
            }
            if(pre[dest]) break;
        }
        //若没有增流路径，跳出循环
        if(!pre[dest]) break;

        //对增流路径增流
        int curr = dest;
        while(curr != src){
            int prev = abs(pre[curr]);
            if(pre[curr] > 0){
                flow[prev][curr] += delta[dest];
            } else {
                flow[curr][prev] -= delta[dest];
            }
            curr = prev;
        }
        ret += delta[dest];
    }
    return ret;
}

int main(){
    int n, m;
    vector<vector<int>> adjm;
    while(cin >> n >> m){
        adjm.clear();
        adjm.resize(m+1, vector<int>(m+1, 0));
        int u, v, f;
        for(int i = 0; i < n; ++i){
            cin >> u >> v >> f;
            if(u == v) continue;
            adjm[u][v] += f;
        }
        cout << maxFlow(adjm, 1, m) << endl;
    }
    return 0;
}
