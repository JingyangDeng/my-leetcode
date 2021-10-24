//状态压缩+记忆化搜索
//执行用时：8 ms, 在所有 C++ 提交中击败了97.03% 的用户
//内存消耗：10.8 MB, 在所有 C++ 提交中击败了78.71% 的用户

class Solution {
public:
    unordered_map<int, int> dp;
    unordered_map<int, int> sp;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int cur_state = vec2int(needs, 0, needs.size());
        for (auto& s : special) {
            int state = vec2int(s, 0, s.size() - 1);
            if (sp.find(state) == sp.end())
                sp[state] = s.back();
            else
                sp[state] = min(sp[state], s.back());
        }
        return min_price(cur_state, price);
    }

    int min_price(int cur_state, vector<int>& price) {
        if (dp.find(cur_state) != dp.end())
            return dp[cur_state];
        int ret = single_buy(cur_state, price);
        for (auto [s, p] : sp) {
            if (can_buy(cur_state, s)) {
                ret = min(ret, p + min_price(cur_state - s, price));
            }
        }
        return dp[cur_state] = ret;
    }

    int single_buy(int cur_state, vector<int>& price) {
        int ret = 0;
        auto it = price.rbegin();
        while (cur_state > 0) {
            int need = cur_state & 0xf;
            ret += need * (*it);
            cur_state >>= 4;
            it++;
        }
        return ret;
    }

    int vec2int(const vector<int>& vec, int i, int j) {
        int ret = 0;
        for (int k = i; k < j; k++) {
            ret <<= 4;
            ret += vec[k];
        }
        return ret;
    }

    bool can_buy(int need, int state) {
        while (state > 0) {
            int a = need & 0xf;
            int b = state & 0xf;
            if (a < b)
                return false;
            need >>= 4;
            state >>= 4;
        }
        return true;
    }
};
