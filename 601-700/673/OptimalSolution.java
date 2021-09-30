//执行用时：5 ms, 在所有 Java 提交中击败了99.90% 的用户
//内存消耗：37.7 MB, 在所有 Java 提交中击败了88.37% 的用户
//
//在Solution.cpp的基础上，在对行的检索中采用二分优化，并简化了所使用的数据结构
class OptimalSolution {
    private ArrayList<ArrayList<Integer>> dp = new ArrayList<>();
    private ArrayList<ArrayList<Integer>> cnt = new ArrayList<>();

    public int findNumberOfLIS(int[] nums) {
        for(int i = nums.length-1; i >= 0; i--){
            int r = binarySearchRow(nums[i]);
            if(r == dp.size()){
                ArrayList<Integer> lst = new ArrayList<>();
                lst.add(nums[i]);
                dp.add(lst);
            } else {
                ArrayList<Integer> lst = dp.get(r);
                lst.add(nums[i]);
            }

            int c = binarySearchCol(r-1, nums[i]);
            if(c == -1){
                if(cnt.size() == 0){
                    ArrayList<Integer> lst = new ArrayList<>();
                    lst.add(1);
                    cnt.add(lst);
                } else {
                    ArrayList<Integer> lst = cnt.get(0);
                    lst.add(1);
                }
            } else {
                ArrayList<Integer> lst = cnt.get(r-1);
                int co = 0;
                for(int j = c; j < lst.size(); j++) co += lst.get(j);
                if(r == cnt.size()){
                    lst = new ArrayList<>();
                    lst.add(co);
                    cnt.add(lst);
                } else {
                    lst = cnt.get(r);
                    lst.add(co);
                }
            }
        }
        int n = cnt.size();
        int ret = 0;
        for(int co : cnt.get(n-1)) ret += co;
        return ret;
    }

    private int binarySearchRow(int num){
        int n = dp.size();
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            ArrayList<Integer> lst = dp.get(mid);
            int len = lst.size();
            if(num >= lst.get(len-1)) r = mid;
            else l = mid + 1;
        }
        if(l == n-1){
            int len = dp.get(n-1).size();
            if(num < dp.get(n-1).get(len-1)) return n;
        }
        return l;
    }

    private int binarySearchCol(int row, int num){
        if(row == -1) return -1;
        ArrayList<Integer> lst = dp.get(row);
        int n = lst.size();
        int l = 0, r = n-1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(num < lst.get(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
}
