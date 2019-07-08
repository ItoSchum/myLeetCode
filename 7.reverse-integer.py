class Solution:
	def reverse(self, x: int) -> int:

		reversed_x = 0
		max_value = 2 ** 31 - 1
		min_value = -max_value - 1
		abs_x = abs(x)
		
		while(abs_x != 0):
			popped_int = abs_x % 10
			abs_x = abs_x // 10
			reversed_x = reversed_x * 10 + popped_int
		
		if x < 0:
			reversed_x = -reversed_x
			
		if reversed_x > max_value or reversed_x < min_value:
			return 0
		else:
			return reversed_x