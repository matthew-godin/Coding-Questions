class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        myHash = {}
        i = 0
        for num in nums:
            valMissing = target - num
            if valMissing in myHash:
                return [myHash[valMissing], i]
            myHash[num] = i
            i += 1
        