#!/usr/bin/env python3

from collections import ``

class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if s[0] == '-':
            num = 0
            for i in s[1:]:
                i = ord(i) - ord('0')
                if i not in range(0, 10):
                    break
                num = num * 10 + i
            num = -num
        elif ord(s[0])-ord('0') in [i for i in range(0, 10)]:
            num = 0
            for i in s[0:]:
                i = ord(i) - ord('0')
                if i not in range(0, 10):
                    break
                num = num * 10 + i
        else:
            return 0
        return num


if __name__ == '__main__':
    sy = Solution()
    print(sy.myAtoi("987"))
