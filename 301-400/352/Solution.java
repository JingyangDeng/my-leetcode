//并查集，使用parent[i] = -1表示不在集合中
//单次addNum O(logn)，getIntervals O(n)
class SummaryRanges {
    private class Dsu {
        private TreeSet<Integer> root;
        private int[] parent;
        private int[] max;
        private int[] min;

        public Dsu(int n){
            root = new TreeSet<>();
            parent = new int[n];
            max = new int[n];
            min = new int[n];
            for(int i = 0; i < n; i++){
                parent[i] = -1;
                max[i] = -1;
                min[i] = -1;
            }
        }

        public void add(int n){
            if(parent[n] >= 0) return;
            root.add(n);
            parent[n] = n;
            max[n] = n;
            min[n] = n;
            union(n+1, n);
            union(n-1, n);
        }

        private int find(int i){
            if(parent[i] != i) parent[i] = find(parent[i]);
            return parent[i];
        }

        private void union(int m, int n){
            if(m < 0 || m >= parent.length || parent[m] < 0) return;
            int mParent = find(m);
            int nParent = find(n);
            if(mParent != nParent){
                root.remove(nParent);
                max[mParent] = Math.max(max[nParent], max[mParent]);
                min[mParent] = Math.min(min[nParent], min[mParent]);
                parent[nParent] = mParent;
            }
        }

        public int[][] getIntervals(){
            int n = root.size();
            int[][] ret = new int[n][2];
            int p = 0;
            for(int r : root){
                ret[p][0] = min[r];
                ret[p][1] = max[r];
                p++;
            }
            return ret;
        }
    }

    private Dsu dsu;
    public SummaryRanges() {
        dsu = new Dsu(10001);
    }
    
    public void addNum(int val) {
        dsu.add(val);
    }
    
    public int[][] getIntervals() {
        return dsu.getIntervals();
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * int[][] param_2 = obj.getIntervals();
 */
