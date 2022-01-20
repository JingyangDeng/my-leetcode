// BFS求无权图最短路径, 注意对第三种跳跃对应的边的剪枝，可将复杂度从O(n^2)降至O(n)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> visited(n, 0);
        unordered_set<int> visitedValue;
        unordered_map<int, unordered_set<int>> nodesByValue;
        for (int i = 0; i < n; ++i) {
            nodesByValue[arr[i]].insert(i);
        }
        queue<pair<int, int>> q = {};
        q.push(make_pair(0, 0));
        visited[0] = 1;
        while (!q.empty()) {
            auto [v, cnt] = q.front();
            q.pop();
            if (visitedValue.find(arr[v]) == visitedValue.end()) {
                visitedValue.insert(arr[v]);
                for (auto w : nodesByValue[arr[v]]) {
                    if (visited[w])
                        continue;
                    if (w == n - 1)
                        return cnt + 1;
                    q.push(make_pair(w, cnt + 1));
                    visited[w] = 1;
                }
            }
            if (v > 0 && !visited[v - 1]) {
                q.push(make_pair(v - 1, cnt + 1));
                visited[v - 1] = 1;
            }
            if (v < n - 1 && !visited[v + 1]) {
                if (v == n - 2)
                    return cnt + 1;
                q.push(make_pair(v + 1, cnt + 1));
                visited[v + 1] = 1;
            }
        }
        return 0;
    }
};
