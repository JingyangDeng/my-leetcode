//考虑相邻洗衣机之间最终衣服的流向
//若初始状态为：9 1 8 8 9，则
//流向（向右为正）为：2 -4 -3 -2 （4次，第二台洗衣机能同时向两边收）
//若初始状态为：0 3 0 1，则
//流向为：-1 1 0（1+1=2次，第二台洗衣机不能同时往两边给）
class Solution {
    public int findMinMoves(int[] machines) {
        int sum = 0, ret = 0;
        for(int i = 0; i < machines.length; i++){
            sum += machines[i];
        }
        if(sum % machines.length != 0) return -1;
        int avg = sum / machines.length;
        int f = 0;
        for(int i = 0; i < machines.length; i++){
            int newF = machines[i] + f - avg;
            if(f < 0 && newF > 0){
                ret = Math.max(ret, newF - f);
            } else {
                ret = Math.max(ret, Math.abs(f));
                ret = Math.max(ret, Math.abs(newF));
            }
            f = newF;
        }
        return ret;
    }
}
