//前缀和+快速选择
class Solution {
private:
    int quick_select(vector<int>& nums, int k){
        int left = 0, right = nums.size();
        while(true){
            int m = rand() % (right - left) + left;
            swap(nums[m], nums[right-1]);
            int pointer = left;
            for(int i = left; i < right-1; i++){
                if(nums[i] > nums[right-1]) {
                    swap(nums[i], nums[pointer]);
                    pointer++;
                }
            }
            swap(nums[pointer], nums[right-1]);
            int pointer_max = pointer;
            while(pointer_max < right && nums[pointer] == nums[pointer_max]) pointer_max++;
            if(pointer_max >= k && pointer <= k-1) break;
            if(pointer_max < k) left = pointer_max;
            else right = pointer;
        }
        return nums[k-1];
    }
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> value(m*n);
        value[0] = matrix[0][0];
        for(int j = 1; j < n; j++) {
            value[j] = matrix[0][j] ^ value[j-1];
        }
        for(int i = 1; i < m; i++){
            value[n*i] = matrix[i][0] ^ value[(i-1)*n];
            for(int j = 1; j < n; j++){
                value[n*i+j] = matrix[i][j] ^ value[(i-1)*n+j] ^ value[i*n+j-1] ^ value[(i-1)*n+j-1];
            }
        }
        return quick_select(value, k);
    }
};
