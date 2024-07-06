class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> combinations;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int candidate = nums[i] + nums[l] + nums[r];
                if (candidate == 0) {
                    vector<int> combination;
                    combination.push_back(nums[i]);
                    combination.push_back(nums[l]);
                    combination.push_back(nums[r]);
                    sort(combination.begin(), combination.end());
                    if (combinations.find(combination) == combinations.end()) {
                        result.push_back(combination);
                        combinations.insert(combination);
                    }
                    int previousL = nums[l];
                    while (l < r && previousL == nums[l]) {
                        ++l;
                    }
                } else if (candidate > 0) {
                    int previousR = nums[r];
                    while (l < r && previousR == nums[r]) {
                        --r;
                    }
                } else {
                    int previousL = nums[l];
                    while (l < r && previousL == nums[l]) {
                        ++l;
                    }
                }
            }
            int previousI = nums[i];
            while (i < nums.size() && previousI == nums[i]) {
                ++i;
            }
        }
        return result;
    }
};