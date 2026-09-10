class Solution(object):
    def isInterleave(self, s1, s2, s3):

        if len(s1) + len(s2) != len(s3):
            return False

        memo = {}

        def check(i, j):
            if i == len(s1) and j == len(s2):
                return True

            if (i, j) in memo:
                return memo[(i, j)]

            k = i + j

            # Take character from s1
            if i < len(s1) and s1[i] == s3[k]:
                if check(i + 1, j):
                    memo[(i, j)] = True
                    return True

            # Take character from s2
            if j < len(s2) and s2[j] == s3[k]:
                if check(i, j + 1):
                    memo[(i, j)] = True
                    return True

            memo[(i, j)] = False
            return False

        return check(0, 0)