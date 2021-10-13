//简单逻辑
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        for (int i = 1; i <= n; i++) {
            bool f1 = i % 3 == 0;
            bool f2 = i % 5 == 0;
            if (f1 && f2)
                ret[i - 1] = "FizzBuzz";
            else if (f1)
                ret[i - 1] = "Fizz";
            else if (f2)
                ret[i - 1] = "Buzz";
            else
                ret[i - 1] = to_string(i);
        }
        return ret;
    }
};
