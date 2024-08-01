class Solution:
    def countSeniors(self, details: List[str]) -> int:
        res = 0
        for person in details:
            if (person[11:13] > "60"):
                res = res + 1
        return res        
