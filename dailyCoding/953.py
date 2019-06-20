from typing import List, Tuple, Dict


class myUnion:
    def __init__(self):
        self.pd = dict()

    def find(self, p):
        self.pd.setdefault(p, p)
        if p != self.pd[p]:
            self.pd[p] = self.find(self.pd[p])
        return self.pd[p]

    def union(self, p1, p2):
        x = self.find(p1)
        y = self.find(p2)
        if x != y:
            self.pd[x] = y
            return

    def count(self):
        res = set()
        for k in self.pd.keys():
            v = self.find(k)
            res.add(v)
        return len(res)


class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        N = len(grid)
        d = myUnion()
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                for t in range(4):
                    d.find((i, j, t))

                if v == '/':
                    d.union((i, j, 0), (i, j, 3))
                    d.union((i, j, 1), (i, j, 2))
                elif v == '\\':
                    d.union((i, j, 0), (i, j, 1))
                    d.union((i, j, 2), (i, j, 3))
                else:
                    d.union((i, j, 0), (i, j, 1))
                    d.union((i, j, 2), (i, j, 3))
                    d.union((i, j, 0), (i, j, 2))

        for i in range(N):
            for j in range(N):
                if (i + 1 < N):
                    d.union((i, j, 1), (i + 1, j, 3))
                if (j + 1 < N):
                    d.union((i, j, 2), (i, j + 1, 0))

        return d.count()


print(Solution().regionsBySlashes(["\\/\\ ", " /\\/", " \\/ ", "/ / "]))
