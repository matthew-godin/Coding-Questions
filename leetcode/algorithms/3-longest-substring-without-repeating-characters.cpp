#include <unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lettersSeen(128, -1);
        int longestLengthSoFar = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (lettersSeen[s[right]] >= left) {
                left = lettersSeen[s[right]] + 1;
            }
            lettersSeen[s[right]] = right;
            int currentLength = right - left + 1;
            if (currentLength > longestLengthSoFar) {
                longestLengthSoFar = currentLength;
            }
        }
        return longestLengthSoFar;
    }
};