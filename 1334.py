#!/usr/bin/env python3

import sys


class Solution:
    def findTheCity(self, n: int, edges: List[List[int]],
                    distanceThreshold: int) -> int:
        graph = []
        for i in n:
            graph.push_back([sys.maxsize] * n)
