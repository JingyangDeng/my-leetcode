//序列自动机f：f[i][j]为第i个位置（包含i）之后j字符第一次出现的位置，加速查找子字符串的过程
//f可通过动态规划求得，详见initF函数
class OptimalSolution {
    public int n;
    public int[][] f;

    public String findLongestWord(String s, List<String> dictionary) {
        n = s.length();
        initF(s, dictionary);
        
        String curStr = "";
        for(String str : dictionary){
            if(contains(s, str) && isPrior(str, curStr)){
                curStr = str;
            }
        }
        return curStr;
    }

    private boolean isPrior(String s1, String s2){
        return s1.length() > s2.length() || (s1.length() == s2.length() && s1.compareTo(s2) < 0);
    }

    private void initF(String s, List<String> dictionary){
        f = new int[n][26];
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 26; j++){
                if(s.charAt(i) == j + 'a') f[i][j] = i;
                else try{
                    f[i][j] = f[i+1][j];
                } catch(IndexOutOfBoundsException e){
                    f[i][j] = n;
                }
            }
        }
    }

    private boolean contains(String s1, String s2){
        int i = 0, j = 0;
        while(i < n && j < s2.length()){
            i = f[i][s2.charAt(j) - 'a'] + 1;
            j++;
        }
        return j == s2.length() && i <= n;
    }
}
