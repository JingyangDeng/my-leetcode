//执行用时：31 ms, 在所有 Java 提交中击败了100.00% 的用户
//内存消耗：50.7 MB, 在所有 Java 提交中击败了96.67% 的用户

//FenwickTree 树状数组
//把不同的值当做一个个桶，桶里放该值的个数，求动态数组的前缀和
class FenwickTree {
    private int[] arr;
    public FenwickTree(int n){
        arr = new int[n+1];
    }
    public void update(int i){
        while(i < arr.length){
            arr[i]++;
            i += (i & (-i));
        }
    }
    public int cumsum(int i){
        int sum = 0;
        while(i > 0){
            sum += arr[i];
            i -= (i & (-i));
        }
        return sum;
    }
}

class Solution {
    public int createSortedArray(int[] instructions) {
        int ub = 0;
        for(int num : instructions) ub = Math.max(ub, num);
        FenwickTree tree = new FenwickTree(ub);
        long ret = 0;
        for(int i = 0; i < instructions.length; i++){
            ret += Math.min(tree.cumsum(instructions[i]-1), i - tree.cumsum(instructions[i]));
            tree.update(instructions[i]);
        }
        ret %= 1000000007;
        return (int)ret;
    }
}
