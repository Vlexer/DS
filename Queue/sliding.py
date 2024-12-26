def maxSlidingWindow(nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        maxi = float('-inf')
        Q = []
        res = []
        for i in range ( 0, k ):
            Q.append(nums[i])
            
        maxi = max ( Q )
        for i in range (k, len(nums)):
            res.append(maxi)
            Q.pop(0)
            Q.append(nums[i])
            if k > 1:
                maxi = max ( nums[i], maxi )
            else:
                maxi = nums[i]
            
        res.append(max(Q))
        return res
    
    
    
def sliding ( nums, k ):
    Q = []
    res = []
    Max = float('-inf')
    secMax = float ('-inf')
    for i in range (k):
        Q.append(nums[i])
        if nums[i] > Max:
            secMax = Max
            Max = nums[i]
        elif nums[i] > secMax:
            secMax = nums[i]
    res.append(Max)
    for i in range (k , len(nums)):
        
        
        x = Q.pop(0)
        Q.append(nums[i])
        if x == Max:
            Max = secMax
            secMax = x
        elif nums[i] > Max:
            secMax = Max
            Max = nums[i]
        elif nums[i] > secMax:
            secMax = nums[i]
        res.append(Max)
    return res
        
    
print(sliding([1,3,-1,-3,5,3,6,7], 3))