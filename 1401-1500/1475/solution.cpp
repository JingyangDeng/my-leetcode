//单调栈
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>> st;
        vector<int> ret(prices.size());

        prices.emplace_back(0);
        for(int i = 0; i < prices.size(); ++i){
            while(!st.empty() && st.top().first >= prices[i]){
                ret[st.top().second] = st.top().first - prices[i];
                st.pop();
            }
            st.push({prices[i], i});
        }
        return ret;
    }
};
