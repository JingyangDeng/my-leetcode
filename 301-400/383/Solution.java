//Hash
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] mCnt = new int[26];
        int[] nCnt = new int[26];
        for(int i = 0; i < ransomNote.length(); ++i){
            ++nCnt[ransomNote.charAt(i) - 'a'];
        }
        for(int i = 0; i < magazine.length(); ++i){
            ++mCnt[magazine.charAt(i) - 'a'];
        }
        for(int i = 0; i < 26; ++i){
            if(mCnt[i] < nCnt[i]) return false;
        }
        return true;
    }
}
