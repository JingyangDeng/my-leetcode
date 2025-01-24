# O(n), 先计算做完所有亏钱交易后的余额balance，考虑临界情况
# 1.进行最后一笔亏钱交易, 支付cost后暂时没有获得最大的cashback: balance + max_cashback
# 2.进行第一笔赚钱交易要先垫付最大的cost: balance + max_cost
class Solution:
    def minimumMoney(self, transactions: List[List[int]]) -> int:
        balance = 0
        max_back = 0
        max_cost = 0
        for t in transactions:
            if t[0] > t[1]:
                balance += t[0] - t[1]
                max_back = max(max_back, t[1])
            else:
                max_cost = max(max_cost, t[0])
        return balance + max(max_back, max_cost)
