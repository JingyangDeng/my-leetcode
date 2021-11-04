//找规律，找出唯一的0的位置即可
class Solution {
public:
    string maximumBinaryString(string binary) {
        int num_zero = 0;
        int start = -1;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '0') {
                if (start == -1)
                    start = i;
                num_zero++;
            }
        }
        for (int i = 0; i < binary.size(); i++) {
            if (i == num_zero + start - 1)
                binary[i] = '0';
            else
                binary[i] = '1';
        }
        return binary;
    }
};
