//快速选组
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.empty())
            return vector<int>();
        nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
