# 将1的数量三等分
class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        cnt = sum(arr)
        if cnt % 3 != 0:
            return [-1, -1]
        if cnt == 0:
            return [0, len(arr) - 1]
        target = cnt // 3
        curr = 0
        head = [-1] * 3
        for p in range(len(arr)):
            if arr[p]:
                if curr % target == 0:
                    head[curr // target] = p
                curr += 1
        arr = [str(a) for a in arr]
        str1 = ''.join(arr[head[0]:head[1]])
        str2 = ''.join(arr[head[1]:head[2]])
        str3 = ''.join(arr[head[2]:])
        # 只需要判断str1和str2是不是以str3开头的
        if str1.find(str3) == -1 or str2.find(str3) == -1:
            return [-1, -1]
        return [head[1] - (len(str1) - len(str3)) - 1, head[2] - (len(str2) - len(str3))]
