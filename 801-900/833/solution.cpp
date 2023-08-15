//模拟
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string res = "";
        int m = s.size();
        int n = indices.size();
        vector<int> f(m, -1);
        for(int i = 0; i < n; ++i) {
            int k = 0;
            while(k < sources[i].size() && k+indices[i] < s.size() && s[k+indices[i]] == sources[i][k]) ++k;
            if(k == sources[i].size()) {
                for(int j = 0; j < k; ++j) f[indices[i] + j] = -2;
                f[indices[i]] = i;
            }
        }
        for(int i = 0; i < s.size(); ++i) {
            if(f[i] >= 0) res += targets[f[i]];
            else if(f[i] == -1) res += s[i];
        }
        return res;
    }
};
