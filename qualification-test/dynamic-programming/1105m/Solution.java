//从后往前，考虑新开一层放第i~n本书所需要的最少高度h[i]
//考虑i-1时，遍历第一层可能的放书情况，即第i-1~k本书放在第一层
//(books[i-1][0] + ... + books[k][0] <= shelfWidth)
//则此时的高度为h[k + 1] + max(books[i-1][1]~books[k][1])
//对这些可能的情况优中选优
class Solution {
    public int minHeightShelves(int[][] books, int shelfWidth) {
        int n = books.length;
        int[] arr = new int[n + 1];
        arr[n] = 0;
        for(int i  = n - 1; i >= 0; --i){
            int curWidth = 0;
            int curHeight = 0;
            int minHeight = Integer.MAX_VALUE;
            for(int j = i; j < n; ++j){
                curWidth += books[j][0];
                if(curWidth > shelfWidth) break;
                curHeight = Math.max(curHeight, books[j][1]);
                minHeight = Math.min(minHeight, curHeight + arr[j + 1]);
            }
            arr[i] = minHeight;
        }
        return arr[0];
    }
}
