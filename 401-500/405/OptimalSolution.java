class OptimalSolution {
    public String toHex(int num) {
        if(num == 0) return "0";
        String[] c = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};
        String ret = "";
        while(num != 0){
            ret = c[num & 15] + ret;
            num >>>= 4;
        }
        return ret;
    }
}
