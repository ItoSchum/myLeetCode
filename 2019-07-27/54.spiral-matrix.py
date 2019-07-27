class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        rows_num = len(matrix)
        cols_num = len(matrix[0])

        haveChecked = [[False] * cols_num for row in matrix]
        
        row_step = [0,  1,  0, -1]
        col_step = [1,  0, -1,  0]

        spiralOrderOuput = []
        
        row = col = 0
        step_index = 0

        for element in range(rows_num * cols_num):
            spiralOrderOuput.append(matrix[row][col])
            haveChecked[row][col] = True

            next_row = row + row_step[step_index]
            next_col = col + col_step[step_index]

            if (0 <= next_row < rows_num) and (0 <= next_col < cols_num) and not haveChecked[next_row][next_col]:
                row = next_row
                col = next_col
            else:
                step_index = (step_index + 1) % 4
                row = row + row_step[step_index]
                col = col + col_step[step_index]

        return spiralOrderOuput

# Runtime: 36 ms, faster than 76.40% of Python3 online submissions for Spiral Matrix.
# Memory Usage: 13.9 MB, less than 5.30% of Python3 online submissions for Spiral Matrix.

# TC: O(n), n = rows_num * cols_num
# SC: O(n), n = rows_num * cols_num