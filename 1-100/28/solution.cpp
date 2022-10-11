//KMP算法
class Solution {
    int* makeNext(const string& pattern){
        int n = pattern.size();
        int* next = new int[n];
        int i = 0, k = -1; next[0] = -1;
        while(i < n-1){
            while(k >= 0 && pattern[i] != pattern[k]) k = next[k];
            ++i; ++k;
            if(pattern[i] == pattern[k]) next[i] = next[k];
            else next[i] = k;
        }
        return next;
    }
public:
    int strStr(string haystack, string needle) {
        int* next = makeNext(needle);
        int m = haystack.size(), n = needle.size();
        int i = 0, j = 0;
        while(i < m && j < n){
            if(j == -1 || haystack[i] == needle[j]) {++i; ++j;}
            else j = next[j]; 
        }
        if(j >= needle.size()) return i - needle.size();
        return -1;
    }
};
