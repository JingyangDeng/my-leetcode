//简单的字符串处理，O(n)
class Solution {
    public String licenseKeyFormatting(String s, int k) {
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) != '-') cnt++;
        }
        if(cnt == 0) return "";
        int r = (cnt % k == 0) ? k : cnt % k;
        int n = (cnt % k == 0) ? cnt / k - 1 : cnt / k;
        char[] ch = new char[cnt + n];
        int i = 0, j = 0;
        while(j < r){
            if(s.charAt(i) != '-'){
                ch[j++] = s.charAt(i);
            }
            i++;
        }
        int ttl;
        for(int round = 0; round < n; round++){
            ch[j++] = '-';
            ttl = k;
            while(ttl > 0){
                if(s.charAt(i) != '-'){
                    ch[j++] = s.charAt(i);
                    ttl--;
                }
                i++;
            }
        }
        return new String(ch).toUpperCase();
    }
}
