//两次遍历
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        int a = 0, b = 0;
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] == guess[i]) {
                a++;
            } else {
                m[guess[i]]++;
            }
        }
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] != guess[i] && m.find(secret[i]) != m.end() && m[secret[i]] > 0) {
                b++;
                m[secret[i]]--;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
