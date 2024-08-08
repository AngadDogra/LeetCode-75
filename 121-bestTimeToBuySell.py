class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left = 0  # Buy pointer
        res = 0  # Maximum profit

        for right in range(1, len(prices)):
            # Calculate profit with the current window
            if prices[right] > prices[left]:
                profit = prices[right] - prices[left]
                res = max(res, profit)
            else:
                # Move the left pointer to right if we found a new lower price
                left = right

        return res

