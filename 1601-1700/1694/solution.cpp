//模拟
class Solution {
public:
    string reformatNumber(string number) {
        vector<char> v;
        for(int i = 0; i < number.size(); ++i){
            if(number[i] >= '0' && number[i] <= '9') v.push_back(number[i]);
        }
        int n = v.size();
        int grp = (n - 1) / 3;
        int p1 = 0, p2 = 0;
        string ret(n + grp, '-');
        while(p2 < n + grp){
            if(n - p1 > 4 || n - p1 == 3) for(int j = 0; j < 3; ++j) ret[p2++] = v[p1++]; 
            else for(int j = 0; j < 2; ++j) ret[p2++] = v[p1++];
            p2++;
        }
        return ret;
    }
};
