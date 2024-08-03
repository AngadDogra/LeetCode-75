class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        target_sorted = sorted(target)
        arr_sorted = sorted(arr)

        if arr_sorted == target_sorted:
            return True
        return False    

