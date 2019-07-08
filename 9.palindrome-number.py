class Solution:
	def isPalindrome(self, x: int) -> bool:
		
		if x < 0:
			return False
		else:
			revesed_x = (str(x)[::-1])
			return revesed_x == str(x)
