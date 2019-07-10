class Solution:
    def intToRoman(self, num: int) -> str:
        
        # mapping_int_to_roman = {
        #     1000: "M", 
        #     900: "CM", 
        #     500:  "D", 
        #     400: "CD", 
        #     100:  "C", 
        #     90:  "XC", 
        #     50:   "L",
        #     40:  "XL",
        #     10:   "X", 
        #     5:    "V", 
        #     1:    "I"
        # }

        num_int =   [1000,  900, 500,  400, 100,  90,  50,    40,  10,    9,   5,    4,   1]
        num_roman = [ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"] 

        roman_output = ""
        resume_index = 0
        
        while num > 0:
            for i in range(resume_index, len(num_int)):
                if num >= num_int[i]:
                    roman_output += num_roman[i]
                    num -= num_int[i]
                    resume_index = i
                    break

        return roman_output


# Runtime: 60 ms, faster than 56.06% of Python3 online submissions for Integer to Roman.
# Memory Usage: 13.5 MB, less than 6.32% of Python3 online submissions for Integer to Roman.

# TC: O(n!), n = num_roman
# SC: O(n), n = num
