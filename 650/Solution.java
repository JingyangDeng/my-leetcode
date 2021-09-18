//使用欧拉筛法筛出质数进行预处理，分解质因数求和。
class Solution {
    private final static ArrayList<Integer> primeList = new Prime(1000).Euler();
    public int minSteps(int n) {
        int ret = 0; 
        for(int p : primeList){
            if(n == 1) return ret;
            while(n % p == 0){
                n /= p;
                ret += p;
            }
        }
        return ret;
    }
}

class Prime{
    private int num;
    private boolean[] check;
    private ArrayList<Integer> primeList;

    public Prime(int n){
        num = n;
        check = new boolean[n+1];
        primeList = new ArrayList<>();
    }

    public ArrayList<Integer> Euler() {
        if(!primeList.isEmpty()) return primeList;
        for (int indexI = 2; indexI <= num; indexI++) {
            if (!check[indexI]) {
                primeList.add(indexI);
            }
            for (int indexJ = 0; indexJ < primeList.size(); indexJ++) {
                if (indexI * primeList.get(indexJ) > num) {
                    break;
                }
                check[indexI * primeList.get(indexJ)] = true;
                if (indexI % primeList.get(indexJ) == 0) {
                    break;
                }
            }
        }
        return primeList;
    }
}

