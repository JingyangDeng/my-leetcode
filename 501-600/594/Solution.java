//Hash + 一次遍历
class Solution {
    public int findLHS(int[] nums) {
        HashMap<Integer, Integer> count = new HashMap<>();
        for(int n : nums){
            count.put(n, count.getOrDefault(n, 0) + 1);
        }
        int ret = 0;
        for(int k : count.keySet()){
            if(count.containsKey(k + 1)){
                ret = Math.max(ret, count.get(k) + count.get(k + 1));
            }
        }
        return ret;
    }
}

