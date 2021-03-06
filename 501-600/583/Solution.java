//Mark:
//二维动态规划求最长公共子序列
class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        int[][] dp = new int[m+1][n+1];
        //(初始值默认为0)
        //for(int i = 0; i <= m; i++) dp[i][0] = 0;
        //for(int j = 0; j <= n; j++) dp[0][j] = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1.charAt(i-1) == word2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return m + n - 2 * dp[m][n];
    }
}
