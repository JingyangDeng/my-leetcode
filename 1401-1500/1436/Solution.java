//简单的Hash表
class Solution {
    public String destCity(List<List<String>> paths) {
        HashSet<String> hSet = new HashSet<>();
        for(List<String> path : paths){
            hSet.add(path.get(0));
        }
        for(List<String> path : paths){
            if(!hSet.contains(path.get(1))) return path.get(1);
        }
        return "";
    }
}
