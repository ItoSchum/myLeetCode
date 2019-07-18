class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0

        if x == 1 or n == 0:
            return 1

        if x == -1:
            if n % 2 == 0:
                return 1
            else:
                return -1
        
        if n == 1:
            return x
        
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -INT_MAX - 1
        
        n_abs = abs(n)
        
        def sqrt_test(n_abs: int):
            pow_value = x
            expo_test = 1
            while n_abs >= 2 * expo_test:
                pow_value *= pow_value
                if pow_value >= INT_MAX and n > 0:
                    return INT_MAX
                elif pow_value <= INT_MIN and n < 0:
                    return INT_MIN
                expo_test = expo_test << 1
            n_abs -= expo_test
            if n_abs == 0:
                return pow_value 
            else:
                return pow_value * sqrt_test(n_abs)
        
        pow_value = sqrt_test(n_abs)
        
        if n > 0:
            return pow_value
        elif n < 0:
            return 1 / pow_value


# Runtime: 32 ms, faster than 88.39% of Python3 online submissions for Pow(x, n).
# Memory Usage: 13.3 MB, less than 14.93% of Python3 online submissions for Pow(x, n).

# TC: O(log2(n)), n = n_abs
# SC: O(1)

            


        