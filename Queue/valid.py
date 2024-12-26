def longestValidParentheses(s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        braceIndex = []
        top = -1
        validLength = 0
        validLength2 = 0
        max1 = 0
        validLength2 = 0
        max2 = 0
        for i in range(0, len(s)):
            if s[i] == '(':
                    stack.append(s[i])
                    braceIndex.append(i)
            elif s[i] == ')' and len(stack) >= 1:
                    validLength += 2
                    stack.pop()
                    braceIndex.pop()
            elif s[i] == ')' and len(stack) == 0:
                if validLength > max1:
                    max1 = validLength
                    validLength = 0
        if len(stack) != 0 and braceIndex[0] != len(s) - 1:
            stack = []
            validLength2 = 0
            max2 = 0
            k = braceIndex[0]
            if k == 0:
                k = braceIndex[1]
            for i in range(0, k):
                if s[i] == '(':
                    stack.append(s[i])
                    braceIndex.append(i)
                elif s[i] == ')' and len(stack) >= 1:
                    validLength2 += 2
                    stack.pop()
                    braceIndex.pop()
                elif s[i] == ')' and len(stack) == 0:
                    if validLength2 > max2:
                        max2 = validLength2
                        validLength = 0
        validLength -= validLength2 
        # if max > validLength: 
        #     return max
        # elif validLength2 > validLength:
        #     return validLength2
        # else: return validLength
        l = [ max2, max1, validLength, validLength2 ]
        return max(l)
# print(longestValidParentheses("(((()(()"))

print(bin(10)[2:])