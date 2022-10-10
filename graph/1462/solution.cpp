//Warshall算法,O(n^3 + q)
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjm(numCourses, vector<int>(numCourses, 0));
        for(auto& pre : prerequisites) adjm[pre[0]][pre[1]] = 1;
        for(int k = 0; k < numCourses; ++k){
            for(int i = 0; i < numCourses; ++i){
                for(int j = 0; j < numCourses; ++j){
                    adjm[i][j] |= (adjm[i][k] && adjm[k][j]);
                }
            }
        }
        vector<bool> ret(queries.size());
        for(int i = 0; i < queries.size(); ++i){
            ret[i] = adjm[queries[i][0]][queries[i][1]];
        }
        return ret;
    }
};
