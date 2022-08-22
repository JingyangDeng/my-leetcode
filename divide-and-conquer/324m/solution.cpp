//O(n)解法的难点在于发现不需要进行完全的排序就可进行构造
//快速选择算法
class Solution {
    int n, mid;
    void quick_select(vector<int>& nums, int left, int right, int k){
        srand(0);
        int r = left + rand() % (right - left + 1);
        int tmp = nums[right]; nums[right] = nums[r]; nums[r] = tmp;
        int ptr = left;
        for(int i = left; i < right; ++i){
            if(nums[i] < nums[right]){
                tmp = nums[ptr]; nums[ptr] = nums[i]; nums[i] = tmp;
                ++ptr;
            }
        }
        tmp = nums[ptr]; nums[ptr] = nums[right]; nums[right] = tmp;
        if(ptr == k) return;
        if(ptr < k) quick_select(nums, ptr+1, right, k);
        else quick_select(nums, left, ptr-1, k);
    }

public:
    void wiggleSort(vector<int>& nums) {
        n = nums.size();
        mid = (n + 1) / 2 - 1;
        quick_select(nums, 0, n - 1, mid);

        //要点：三向切分，将大于 等于 小于nums[mid]的数分成三部分， O(n)
        for (int k = 0, i = 0, j = n - 1; k <= j; k++) {
            if (nums[k] > nums[mid]) {
                while (j > k && nums[j] > nums[mid]) {
                    j--;
                }
                swap(nums[k], nums[j--]);
            }
            if (nums[k] < nums[mid]) {
                swap(nums[k], nums[i++]);
            }
        }

        vector<int> tmp(nums);
        for(int i = 0; i < n; ++i){
            if(i & 1) nums[i] = tmp[n - (i + 1) / 2];
            else nums[i] = tmp[mid - i / 2];
        }
    }
};
