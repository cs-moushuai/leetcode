#!/usr/bin/env python3

class Solution:
    # def findDisappearedNumbers(self, nums):
    # exam = set()
    # for i in nums:
    # exam.add(i)
    # res = []
    # for i in range(1, len(nums)+1):
    # if i not in exam:
    # res.append(i)
    # return res
    def findDisappearedNumbers(self, nums):
        return list(set([i for i in range(1, len(nums)+1)]) ^ set(nums))


test = [1, 3, 3, 4, 6, 8]
sy = Solution()

print(sy.findDisappearedNumbers(test))
