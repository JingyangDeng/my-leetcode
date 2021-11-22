//考虑s和goal有几位有差别，分情况讨论，一次遍历
class Solution {
    public boolean buddyStrings(String s, String goal) {
        if(s.length() != goal.length()) return false;
        int[] arr = new int[2];
        int[] alpha = new int[26];
        int p = 0;
        for(int i = 0; i < s.length(); ++i){
            ++alpha[s.charAt(i) - 'a'];
            if(s.charAt(i) != goal.charAt(i)){
                if(p >= 2) return false;
                arr[p++] = i;
            }
        }
        if(p == 1) return false;
        if(p == 0){
            for(int i = 0; i < 26; ++i){
                if(alpha[i] > 1) return true;
            }
            return false;
        }
        if(s.charAt(arr[0]) == goal.charAt(arr[1]) && s.charAt(arr[1]) == goal.charAt(arr[0])) return true;
        return false;
    }
}
