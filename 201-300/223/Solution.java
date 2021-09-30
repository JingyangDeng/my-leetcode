//简单的数学逻辑
class Solution {
    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1 = (ax2 - ax1) * (ay2 - ay1);
        int a2 = (bx2 - bx1) * (by2 - by1);
        int a3 = intersectArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        return a1 + a2 - a3;
    }

    private int intersectArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
        if(ax2 < bx1 || bx2 < ax1 || ay2 < by1 || by2 < ay1) return 0;
        int w1 = Math.min(Math.abs(ax2 - bx1), Math.abs(bx2 - ax1));
        int w2 = Math.min(ax2 - ax1, bx2 - bx1);
        int h1 = Math.min(Math.abs(ay2 - by1), Math.abs(by2 - ay1));
        int h2 = Math.min(ay2 - ay1, by2 - by1);
        int w = Math.min(w1, w2);
        int h = Math.min(h1, h2);
        return w * h;
    }
}
