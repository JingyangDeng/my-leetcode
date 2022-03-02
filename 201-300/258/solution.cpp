// 数学性质，O(1)
class Solution {
public:
    int addDigits(int num) {
        return num > 0 ? (num - 1) % 9 + 1 : 0;
    }
};
