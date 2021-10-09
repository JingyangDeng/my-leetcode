//数学观察，排序后+-(sums[1]-sums[0])必有其一在原数组中
//将sums分为S和T，其中S+d=T，且0属于S，递归地在S中找其他原数组中的数
class Solution {
    private int[] sums;
    public int[] recoverArray(int n, int[] sums) {
        int[] ret = new int[n];
        Arrays.sort(sums);
        this.sums = sums;
        for(int i = 0; i < n; i++){
            ret[i] = getNumber();
        }
        return ret;
    }

    private int getNumber(){
        int d = sums[1] - sums[0];
        if(match(d)) return d;
        return -d;
    }

    private boolean match(int d){
        int p = 0, q = 0, r = 0;
        boolean[] visited = new boolean[sums.length];
        int[] newSum1 = new int[sums.length / 2];
        int[] newSum2 = new int[sums.length / 2];
        boolean f = false;
        while(p < sums.length && q < sums.length){
            if(p == q){
                if(d > 0) p++;
                else q++;
            }
            if(sums[p] == sums[q] + d){
                visited[p] = true;
                visited[q] = true;
                if(sums[q] == 0) f = true;
                newSum1[r] = sums[q];
                newSum2[r] = sums[p];
                r++;
            } else if(sums[p] < sums[q] + d) p++;
            else q++;

            while(p < sums.length && visited[p]) p++;
            while(q < sums.length && visited[q]) q++;
        }
        if(f){
            sums = newSum1;
            return true;
        }
        sums = newSum2;
        return false;
    }
}
