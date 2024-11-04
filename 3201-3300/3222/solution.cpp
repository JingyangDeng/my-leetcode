//The only combination: 115 = 1 * 75 + 4 * 10
class Solution {
public:
    string losingPlayer(int x, int y) {
        return min(x, y/4) & 1 ? "Alice" : "Bob";
    }
};
