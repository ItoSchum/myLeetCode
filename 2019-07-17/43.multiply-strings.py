class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        
        def str_to_int(str_input: str):
            num_value = 0
            num_in_serial = []
            num_mapping = {
                '1':1,
                '2':2,
                '3':3,
                '4':4,
                '5':5,
                '6':6,
                '7':7,
                '8':8,
                '9':9,
                '0':0
            }

            str_len = len(str_input)
            for i in range(str_len):
                num_in_serial.append(num_mapping[str_input[i]])

            offset = 0
            for i in range(len(num_in_serial) - 1, -1, -1):
                num_value += num_in_serial[i] * (10 ** offset)
                offset += 1

            return num_value
    
        if num1 == '0' or num2 == '0':
            return '0'
        else:
            num1_value = str_to_int(num1)
            num2_value = str_to_int(num2)
            
            return  str(num1_value * num2_value)
            
# Runtime: 40 ms, faster than 81.87% of Python3 online submissions for Multiply Strings.
# Memory Usage: 13 MB, less than 95.72% of Python3 online submissions for Multiply Strings.

# TC: O(n), n = len(num1) + len(num2)
# SC: O(1)
