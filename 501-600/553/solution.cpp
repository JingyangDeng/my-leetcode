//动态规划O(n^3)，事实上可以证明形如a/(b/c/d/.../z)的表达式是最大的，直接构造的复杂度为O(n)
class Solution {
    int n;
    vector<vector<double>> mmax;
    vector<vector<double>> mmin;
public:
    string optimalDivision(vector<int>& nums) {
        n = nums.size();
        mmax.resize(n, vector<double>(n, -1));
        mmin.resize(n, vector<double>(n, -1));
        for(int i = 0; i < n; ++i){
            mmax[i][i] = nums[i];
            mmin[i][i] = nums[i];
        }
        for(int d = 1; d < n; ++d){
            for(int i = 0; i + d < n; ++i){
                mmax[i][i+d] = INT_MIN;
                mmin[i][i+d] = INT_MAX;
                for(int k = i; k < i + d; ++k){
                    if(mmax[i][i+d] < mmax[i][k] / mmin[k+1][i+d]){
                        mmax[i][i+d] = mmax[i][k] / mmin[k+1][i+d];
                        mmax[i+d][i] = k;
                    }
                    if(mmin[i][i+d] > mmin[i][k] / mmax[k+1][i+d]){
                        mmin[i][i+d] = mmin[i][k] / mmax[k+1][i+d];
                        mmin[i+d][i] = k;
                    }
                }
            }
        }
        return get_max_string(nums, 0, n-1);
    }

    string get_max_string(vector<int>& nums, int l, int r){
        //cout << l << " max " << r << endl;
        if(r == l) return to_string(nums[l]);
        int m = mmax[r][l];
        if(m+1 == r) return get_max_string(nums, l, m) + "/" + to_string(nums[r]);
        return get_max_string(nums, l, m) + "/(" + get_min_string(nums, m+1, r) + ")";
    }

    string get_min_string(vector<int>& nums, int l, int r){
        //cout << l << " min " << r << endl;
        if(r == l) return to_string(nums[l]);
        int m = mmin[r][l];
        if(m+1 == r) return get_min_string(nums, l, m) + "/" + to_string(nums[r]);
        return get_min_string(nums, l, m) + "/(" + get_min_string(nums, m+1, r) + ")";
    }
};
