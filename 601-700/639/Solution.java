//执行用时：10 ms, 在所有 Java 提交中击败了90.80% 的用户
//内存消耗：38.6 MB, 在所有 Java 提交中击败了98.77% 的用户
//
//动态规划，每个字母最多由2个字符构成
//考虑前m个字符的解码方法数，列出其与m-1，m-2时的关系即可
class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        long[] dp = new long[n];
        long cnt, factor;
        char curChar, lastChar;
        for(int i = 0; i < n; i++){
            long sum = 0;
            curChar = s.charAt(i);

            if(curChar == '*'){
                cnt = i > 0 ? dp[i-1] : 1;
                sum += cnt * 9;
                sum %= 1000000007;

                try{lastChar = s.charAt(i-1);}
                catch(IndexOutOfBoundsException e){dp[i] = sum; continue;}

                cnt = i > 1 ? dp[i-2] : 1;
                if(lastChar == '*'){factor = 15;}
                else if(lastChar == '2'){factor = 6;}
                else if(lastChar == '1'){factor = 9;}
                else {factor = 0;}
                sum += cnt * factor;
                sum %= 1000000007;
            } else if(curChar > '0') {
                cnt = i > 0 ? dp[i-1] : 1;
                sum += cnt;
                sum %= 1000000007;

                try{lastChar = s.charAt(i-1);}
                catch(IndexOutOfBoundsException e){dp[i] = sum; continue;}

                cnt = i > 1 ? dp[i-2] : 1;
                if(lastChar == '*'){
                    if(curChar > '6'){factor = 1;}
                    else {factor = 2;}
                } else if(lastChar == '2'){
                    if(curChar > '6'){factor = 0;}
                    else {factor = 1;}
                } else if(lastChar == '1'){factor = 1;}
                else {factor = 0;}
                sum += cnt * factor;
                sum %= 1000000007;
            } else {
                try{lastChar = s.charAt(i-1);}
                catch(IndexOutOfBoundsException e){return 0;}

                cnt = i > 1 ? dp[i-2] : 1;
                if(lastChar == '0') return 0;
                if(lastChar == '*'){factor = 2;}
                else if(lastChar == '1' || lastChar == '2'){factor = 1;}
                else {factor = 0;}
                sum += cnt * factor;
                sum %= 1000000007;
            }
            dp[i] = sum;
        }
        return (int)dp[n-1];
    }
}
