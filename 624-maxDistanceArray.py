'''
Find the minimum and maximum of all the arrays ? 
Then find the minimum/maximum in that and return their difference ? 
Create a function that takes in an array as input and returns max and one that returns min?
'''

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        minSeenSoFar = float("infinity")
        maxSeenSoFar = float("-infinity")
        for array in arrays:
            if array[0] < minSeenSoFar:
                minSeenSoFar = array[0]
            if array[len(array) - 1] > maxSeenSoFar:
                maxSeenSoFar = array[len(array) - 1]  

        return (maxSeenSoFar - minSeenSoFar)
        
