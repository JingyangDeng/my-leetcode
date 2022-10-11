//网络最大流 Edmonds Karp算法
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

int maxFlow(const vector<vector<int>>& adjm, int src, int dest){
    int ret = 0;
    int n = adjm.size();
    vector<vector<int>> flow(n, vector<int>(n, 0));

    while(1){
        vector<int> delta(n, 0);
        vector<int> pre(n, INT_MAX);
        delta[src] = INT_MAX; pre[src] = INT_MAX-1;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int w = 0; w < n; ++w){
                if(pre[w] != INT_MAX) continue;
                if(adjm[v][w] > 0 && flow[v][w] < adjm[v][w]){
                    pre[w] = v;
                    delta[w] = min(delta[v], adjm[v][w] - flow[v][w]);
                    q.push(w);
                } else if(adjm[w][v] > 0 && flow[w][v] > 0){
                    pre[w] = -v-1;
                    delta[w] = min(delta[v], flow[w][v]);
                    q.push(w);
                }
            }
            if(pre[dest] != INT_MAX) break;
        }
        if(pre[dest] == INT_MAX) break;
        int curr = dest;
        while(curr != src){
            int prev;
            if(pre[curr] >= 0){
                prev = pre[curr];
                flow[prev][curr] += delta[dest];
            } else {
                prev = -pre[curr]-1;
                flow[curr][prev] -= delta[dest];
            }
            curr = prev;
        }
        ret += delta[dest];
    }
    return ret;
}

int main(int argc, char** argv) {
    int n, np, nc, m;
	while(cin >> n >> np >> nc >> m){
        int src = n, dest = n+1;
        vector<vector<int>> adjm(n+2, vector<int>(n+2, 0));
		for(int i = 1;i <= m; ++i){
			int x, y, w;
			scanf("%*1s%d%*1s%d%*1s%d", &x, &y, &w);
            adjm[x][y] = w;
		}
		for(int i = 1; i <= np; ++i){
			int x, w;
			scanf("%*1s%d%*1s%d",&x,&w);
            adjm[src][x] = w;
		}
		for(int i = 1; i <= nc; ++i){
			int x, w;
			scanf("%*1s%d%*1s%d", &x, &w);
            adjm[x][dest] = w;
		}
        cout << maxFlow(adjm, src, dest) << endl;
	} 
	return 0;
}
