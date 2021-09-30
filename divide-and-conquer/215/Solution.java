//优先队列
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<>(k, new Comparator<Integer>(){
            @Override
            public int compare(Integer a, Integer b) {
                return b - a;
            }
        });  
        for(int n : nums) q.add(n);
        for(int i = 0; i < k-1; i++) q.poll();
        return q.peek();
    }
}
