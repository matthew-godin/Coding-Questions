#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myHashMap;
        for (int i = 0; i < nums.size(); ++i) {
            int valMissing = target - nums[i];
            if (myHashMap.find(valMissing) != myHashMap.end()) {
                vector<int> myResult{ myHashMap[valMissing], i };
                return myResult;
            }
            myHashMap.insert({nums[i], i});
        }
        vector<int> myResult{ 0, 0 };
        return myResult;
    }
};