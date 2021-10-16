// dfs所有表达式再分别计算
class Solution {
private:
    string num, formula = "";
    vector<string> ret = {};
    unordered_set<char> op_set = {'+', '-', '*'};
    stack<pair<long long, char>> st = {};
    long long target;
    int begin, p = 0;

    long long get_num() {
        if (formula[begin] == '0') {
            if (begin + 1 < formula.size() && op_set.find(formula[begin + 1]) == op_set.end())
                return -1;
        }
        long long ret = 0;
        while (begin < formula.size() && op_set.find(formula[begin]) == op_set.end()) {
            ret *= 10;
            ret += formula[begin] - '0';
            begin++;
        }
        return ret;
    }

    long long parse() {
        begin = 0;
        long long cur_n = get_num();
        if (cur_n == -1)
            return (long long)1 << 31;
        if (begin == formula.size())
            return cur_n;
        while (begin < formula.size()) {
            char op = formula[begin++];
            long long n = get_num();
            if (n == -1) {
                while (!st.empty())
                    st.pop();
                return (long long)1 << 31;
            }
            if (op == '*') {
                cur_n *= n;
            } else {
                st.push(make_pair(cur_n, op));
                cur_n = n;
            }
        }
        long long ret = 0;
        while (!st.empty()) {
            auto [n, op] = st.top();
            st.pop();
            if (op == '+') {
                ret += cur_n;
            } else {
                ret -= cur_n;
            }
            cur_n = n;
        }
        ret += cur_n;
        return ret;
    }

    void dfs() {
        char c = num[p];
        formula.push_back(num[p++]);
        if (p < num.size()) {
            formula.push_back('*');
            dfs();
            formula.pop_back();

            formula.push_back('+');
            dfs();
            formula.pop_back();

            formula.push_back('-');
            dfs();
            formula.pop_back();

            dfs();
        } else {
            if (parse() == target) {
                ret.emplace_back(formula);
            }
        }
        formula.pop_back();
        p--;
    }

public:
    vector<string> addOperators(string num, int target) {
        this->target = target;
        this->num = num;
        dfs();
        return ret;
    }
};
