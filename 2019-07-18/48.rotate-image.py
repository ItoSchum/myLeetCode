class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        edge_length = len(matrix)

        matrix.reverse()

        for x in range(edge_length):
            for y in range(x):
                # temp = matrix[y][edge_length - 1 - x]
                # matirx[y][edge_length - 1 - x] = matrix[x][y]
                matrix[x][y], matrix[y][x] = matrix[y][x], matrix[x][y]

# Runtime: 32 ms, faster than 96.16% of Python3 online submissions for Rotate Image.
# Memory Usage: 12.9 MB, less than 99.50% of Python3 online submissions for Rotate Image.

# TC: O(n^2 / 2), n = edge_length
# SC: O(1)
            
