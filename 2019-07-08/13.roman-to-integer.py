class Solution:
	def romanToInt(self, s: str) -> int:
		
		roman_mapping = {
			'I' : 1, 
			'IV': 4,
			'V' : 5, 
			'IX': 9,
			'X' : 10, 
			'XL': 40,
			'L' : 50, 
			'XC': 90,
			'C' : 100,
			'CD': 400, 
			'D' : 500,
			'CM': 900, 
			'M' : 1000
		}

		int_output = 0
		i = 0

		while i < len(s):
			roman_double = s[i : i + 2]
			roman_single = s[i]

			if (roman_double in roman_mapping) and (i + 1 < len(s)):
				int_output += roman_mapping[roman_double]
				i += 1
			else:
				int_output += roman_mapping[roman_single]

			i += 1

		return int_output


# Runtime: 60 ms, faster than 77.02% of Python3 online submissions for Roman to Integer.
# Memory Usage: 13.1 MB, less than 96.79% of Python3 online submissions for Roman to Integer.

# TC: O(n), n = len(s)
# SC: O(1)
		
