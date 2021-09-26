//统一进位，迭代求解
class OptimalSolution {
    public int getSum(int a, int b) {
        int tmp;
        while(b != 0){
            tmp = (a & b) << 1;
            a ^= b;
            b = tmp;
        }
        return a;
    }
}
