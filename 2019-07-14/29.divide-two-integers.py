class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        signed_int_boundary = 2 ** 31
        INT_MAX = signed_int_boundary - 1 
        INT_MIN = -signed_int_boundary

        dividend_abs = abs(dividend)
        divisor_abs = abs(divisor)
        quotient = 0
        step_divisor = divisor_abs
        step_quotient = 1

        if dividend_abs < divisor_abs:
            return 0

        if (dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0):
            sign = -1
        elif (dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0):
            sign = 1
        # else:
            # sign = 0

        if sign == 0:
            return 0

        if divisor_abs == 1:
            if dividend > INT_MAX:
                return INT_MAX
            elif dividend < INT_MIN:
                return INT_MIN
            else:
                output_value = sign * dividend_abs
                if output_value > INT_MAX:
                    return INT_MAX
                else:
                    return output_value

        while dividend_abs >= 0:
            if (dividend_abs - step_divisor) > (step_divisor << 1):
                step_quotient = step_quotient << 1
                step_divisor = step_divisor << 1
            else:
                if dividend_abs - step_divisor < divisor_abs:
                    quotient += step_quotient
                    break
                else:
                    dividend_abs -= step_divisor
                    step_divisor = divisor_abs
                    quotient += step_quotient
                    step_quotient = 1
                    continue

        if sign == 1:
            return quotient
        elif sign == -1:
            return -quotient
    
            
# Runtime: 40 ms, faster than 60.99% of Python3 online submissions for Divide Two Integers.
# Memory Usage: 13.1 MB, less than 95.38% of Python3 online submissions for Divide Two Integers.

# TC: O(log(2)n/m), n = abs(dividend), m = abs(divisor)
# SC: O(1)