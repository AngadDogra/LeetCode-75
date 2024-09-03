class Solution:
    def getLucky(self, s: str, k: int) -> int:
        def helper(num:int) -> int:
            # take num return the sum of its digits
            sum = 0 
            while num > 0:
                sum += (num % 10)
                num = num // 10
            return sum 

        alphabetMap = {
            'a' : 1,
            'b' : 2,
            'c' : 3,
            'd' : 4,
            'e' : 5,
            'f' : 6,
            'g' : 7,
            'h' : 8,
            'i' : 9,
            'j' : 1,
            'k' : 2,
            'l' : 3,
            'm' : 4,
            'n' : 5,
            'o' : 6,
            'p' : 7,
            'q' : 8,
            'r' : 9,
            's' : 10,
            't' : 2,
            'u' : 3,
            'v' : 4,
            'w' : 5,
            'x' : 6,
            'y' : 7,
            'z' : 8,
        }

        sum = 0

        for c in s:
            sum += alphabetMap[c]

        if k > 1:
            while k > 1 :
                sum = helper(sum)    
                k -= 1

        return sum        
            
        
