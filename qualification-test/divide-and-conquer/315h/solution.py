#使用归并排序的思想进行分治，再使用O(n)操作将结果合并
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        lst = [[nums[i], i, 0] for i in range(len(nums))]
        lst = self.merge(lst)
        lst.sort(key=lambda x: x[1])
        return [x[2] for x in lst]
    
    def merge(self, lst):
        n = len(lst)
        mid = n // 2
        if n <= 1:
            return lst
        ret = []
        lst1 = self.merge(lst[:mid])
        lst2 = self.merge(lst[mid:])
        #inc表示已经有多少个lst2中的数比当前的lst1[i]小
        i, j, inc = 0, 0, 0
        while i < mid and j < n-mid:
            if lst1[i][0] > lst2[j][0]:
                inc += 1
                ret.append(lst2[j])
                j += 1
            else:
                lst1[i][2] += inc
                ret.append(lst1[i])
                i += 1
        if i == mid:
            while j < n-mid:
                ret.append(lst2[j])
                j += 1
        else:
            while i < mid:
                lst1[i][2] += inc
                ret.append(lst1[i])
                i += 1
        return ret

