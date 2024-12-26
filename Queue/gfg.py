def longestValidParentheses(s):
        """
        :type s: str
        :rtype: int
        """
        stack = [-1]
        braceIndex = []
        top = -1
        maxLen = 0
        for i in range(0, len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    maxLen = max(maxLen, i - stack[-1])

        return maxLen
print(longestValidParentheses(")()())"))