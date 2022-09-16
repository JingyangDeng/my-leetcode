//由于n不大，可将xs, ys排序后离散化后暴力求解
//将整个区域划分为(2n-1)*(2n-1)块，使用扫描线法统计各块的覆盖情况, O(n^3)
//注：使用线段树复杂度可优化至O(nlogn)
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        long long ret = 0;
        vector<int> xs;
        vector<int> ys;
        for(auto& r : rectangles){
            xs.push_back(r[0]);
            xs.push_back(r[2]);
            ys.push_back(r[1]);
            ys.push_back(r[3]);
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        for(int i = 0; i < 2*n-1; ++i){
            int left = xs[i], right = xs[i+1];
            if(left == right) continue;
            vector<int> block(2*n-1, 0);
            for(auto& r : rectangles){
                if(r[0] <= left && r[2] >= right){
                    int k = 0;
                    while(ys[k] < r[1]) ++k;
                    while(ys[k] < r[3]){
                        if(!block[k]){
                            block[k] = ys[k+1] - ys[k];
                            ret += (long long)block[k] * (right - left);
                        }
                        ++k;
                    }
                }
            }
        }
        return ret % 1000000007;
    }
};
