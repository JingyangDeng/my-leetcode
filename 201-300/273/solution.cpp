//理清逻辑即可做出
class Solution {
private:
    vector<string> number = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> ten_number = {"Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                                 "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> num_ten = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string ret = "";
        int level = 0;
        while (num > 0) {
            int tmp = num % 1000;
            string next = parse(tmp, level);
            if (ret.empty())
                ret = next;
            else if (next.empty())
                ;
            else
                ret = next + " " + ret;
            num /= 1000;
            level++;
        }
        return ret;
    }

    string parse(int x, int level) {
        string ret = "";
        int a = x / 100;
        int b = (x - a * 100) / 10;
        int c = x % 10;
        if (a > 0)
            ret += (number[a - 1] + " Hundred");
        if (b > 1) {
            if (a == 0)
                ret += num_ten[b - 2];
            else
                ret += (" " + num_ten[b - 2]);
            if (c > 0)
                ret += (" " + number[c - 1]);
        } else if (b == 1) {
            if (a == 0)
                ret += ten_number[c];
            else
                ret += (" " + ten_number[c]);
        } else if (c > 0) {
            if (a == 0)
                ret += number[c - 1];
            else
                ret += (" " + number[c - 1]);
        }
        if (!ret.empty()) {
            if (level == 1)
                ret += " Thousand";
            else if (level == 2)
                ret += " Million";
            else if (level == 3)
                ret += " Billion";
        }
        return ret;
    }
};
