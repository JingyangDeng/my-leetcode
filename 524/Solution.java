//双指针判断是否包含子字符串 + 排序优化
class Solution {
    public String findLongestWord(String s, List<String> dictionary) {
        Collections.sort(dictionary, new Comparator<String>(){
            public int compare(String s1, String s2){
                if(s1.length() != s2.length()){
                    return s2.length() - s1.length();
                }
                return s1.compareTo(s2);
            }
        });
        
        for(String str : dictionary){
            if(contains(s, str)) return str;
        }
        return "";
    }

    private boolean contains(String s1, String s2){
        int i = 0;
        int j = 0;
        while(i < s1.length() && j < s2.length()){
            if(s1.charAt(i) == s2.charAt(j)){
                j++;
            }
            i++;
        }
        return j == s2.length();
    }
}
