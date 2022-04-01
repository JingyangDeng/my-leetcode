//hash + 对key排序
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> m1;
        map<int, int> m2;
        for(auto a : arr){
            if(a >= 0) ++m1[a];
            else ++m2[-a];
        }
        return check(m1) && check(m2);
    }

    bool check(map<int, int>& m){
        while(!m.empty()){
            auto [k, v] = *m.begin();
            if(!k){
                if(v & 1) return false;
                m.erase(k);
                continue;
            }
            if(m[k << 1] < v) return false;
            else if(m[k << 1] == v) m.erase(k << 1);
            else m[k << 1] -= v;
            m.erase(k);
        }
        return true;
    }
};
