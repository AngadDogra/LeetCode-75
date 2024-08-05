class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        frequency_map = {}

        for string in arr:
            if string in frequency_map:
                frequency_map[string] += 1
            else:
                frequency_map[string]  = 1  
        
        distinct_strings = [string for string in frequency_map if frequency_map[string] == 1]

   

        if k - 1  < len (distinct_strings):
            return distinct_strings[k-1]
        else:
            return ""    

