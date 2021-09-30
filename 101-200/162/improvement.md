"爬坡法"，二分思想，复杂度为O(log n)：

1. 找到数组中间点i，验证是否有nums[i] > nums[i-1] && nums[i] > nums[i+1];

2. 若nums[i] > nums[i+1]，向左查找，继续取剩余部分的中间点;

3. 若nums[i] < nums[i+1]，向右查找;

