//根据入度的拓扑排序
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> indegs(n+1);
        vector<unordered_set<int>> adj(n+1);
        queue<int> q;
        
        //build graph
        for(auto& seq : sequences){
            for(int i = 0; i < seq.size()-1; ++i){
                int prev = seq[i];
                int next = seq[i+1];
                if(!adj[prev].count(next)){
                    ++indegs[next];
                    adj[prev].emplace(next);
                }
            }
        }

        //init queue
        for(int i = 1; i <= n; ++i){
            if(!indegs[i]) q.push(i);
        }

        //topological order
        while(!q.empty()){
            if(q.size() > 1) return false; // not unique
            int cur = q.front();
            q.pop();
            for(auto next : adj[cur]){
                --indegs[next];
                if(!indegs[next]) q.push(next);
            }
        }
        return true;
    }
};
