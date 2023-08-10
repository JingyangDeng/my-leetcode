//基于快速排序的选择算法，找出最小的k个数
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.empty())
            return vector<int>();
        srand(time(NULL));
        quick_select(arr, k);
        // sort(arr.begin(), arr.begin() + k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }

    void quick_select(vector<int>& arr, int k) {
        int l = 0, r = arr.size();
        int p = -1;
        while (true) {
            p = quick_sort_step(arr, l, r);
            if (p == k)
                return;
            if (p < k)
                l = p + 1;
            else
                r = p;
        }
    }

    int quick_sort_step(vector<int>& arr, int l, int r) {
        int p = l + rand() % (r - l);
        int first = l - 1;
        swap(arr[p], arr[r - 1]);
        for (int i = l; i < r - 1; i++) {
            if (arr[i] < arr[r - 1]) {
                first++;
                swap(arr[first], arr[i]);
            }
        }
        swap(arr[first + 1], arr[r - 1]);
        return first + 1;
    }
};
