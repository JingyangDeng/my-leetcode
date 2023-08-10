#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int EdmondsKarpMaxFlow(const vector<vector<int>>& adjm, int src, int dest){
    int n = adjm.size();
    //初始流设为0流
    int ret = 0;
    vector<vector<int>> flow(n, vector<int>(n, 0));

    while(1){
        queue<int> q;
        vector<int> sign(n, 0);
        vector<int> parent(n, INT_MAX);
        vector<int> delta(n, INT_MAX);
        sign[src] = INT_MAX;
        q.push(src);
        //BFS找增流路径
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int w = 0; w < n; ++w){
                if(sign[w] != 0) continue;
                if(adjm[v][w] > 0 && flow[v][w] < adjm[v][w]){
                    delta[w] = min(delta[v], adjm[v][w] - flow[v][w]);
                    sign[w] = 1;
                    parent[w] = v;
                    q.push(w);
                } else if(adjm[w][v] > 0 && flow[w][v] > 0){
                    delta[w] = min(delta[v], flow[w][v]);
                    sign[w] = -1;
                    parent[w] = v;
                    q.push(w);
                }
            }
            if(sign[dest] != 0) break;
        }
        //若没找到，跳出循环
        if(sign[dest] == 0) break;

        //若找到，通过查找父节点增流
        int curr = dest;
        while(curr != src){
            int prev = parent[curr];
            if(sign[curr] == 1){
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

//n个医生 S_j 为医生j能上班的日期集合，k个假期 D_i为第i个假期包含的日期集合，并记日期从0开始标号，即day_0, day_1,...
int doctor(int n, int k, int c, vector<unordered_set<int>>& S, vector<unordered_set<int>>& D) {
    //d为所有日期的数量
    int d = 0; 
    for(int i = 0; i < k; ++k) d += D[i].size();

    //构造网络 1 - n - n*k - d - 1
    //源：0
    //医生i：i+1 (1~n)
    //(医生j，假期l)：(n+1)+(j*k+l) (n+1~n(k+1))
    //日期day：n(k+1)+1+day (n(k+1)+1~n(k+1)+d)
    //汇：n(k+1)+d+1
    int N = n * (k+1) + d + 2;
    vector<vector<int>> adjm(N, vector<int>(N, 0));
    for(int i = 0; i < n; ++i){
        adjm[0][i+1] = c;
    }
    for(int j = 0; j < n; ++j){
        for(int l = 0; l < k; ++l){
            adjm[j+1][n+1+j*k+l] = 1;
        }
    }
    for(int p = n+1; p <= n*(k+1); ++p){
        int l = (p-n-1) % k;
        int j = (p-n-1) / k;
        for(int day : D[l]){
            if(S[j].count(day)){
                adjm[p][n*(k+1)+1+day] = 1;
            }
        }
    }
    for(int day = n*(k+1)+1; day <= N-2; ++day){
        adjm[day][N-1] = 1;
    }

	return EdmondsKarpMaxFlow(adjm, 0, N-1);
}

