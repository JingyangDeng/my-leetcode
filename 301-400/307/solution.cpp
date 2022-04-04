// Fenwick Tree 构造O(nlogn) 更新&求和O(logn)
// 注：也可使用线段树求解，此时构造复杂度O(n)
class NumArray {
    vector<int> sumTree;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        sumTree.resize(nums.size() + 1, 0);
        this->nums.resize(nums.size(), 0);
        for(int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        updateDelta(index, val - nums[index]);
        nums[index] = val;
    }

    void updateDelta(int index, int delta) {
        ++index;
        while(index < sumTree.size()){
            sumTree[index] += delta;
            index += index & (-index);
        }
    }
    
    int sumRange(int left, int right) {
        return sumAccum(right) - sumAccum(left - 1);
    }

    int sumAccum(int index){
        int ret = 0;
        ++index;
        while(index > 0) {
            ret += sumTree[index];
            index -= index & (-index);
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
