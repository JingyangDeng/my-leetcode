//贪心
class Solution {
    public int balancedStringSplit(String s) {
        int cnt = 0;
        int maxNum = 0;
        for(int index = 0; index < s.length(); index++){
            if(s.charAt(index) == 'R') cnt++;
            else cnt--;
            if(cnt == 0) maxNum++;
        }
        return maxNum;
    }
}
