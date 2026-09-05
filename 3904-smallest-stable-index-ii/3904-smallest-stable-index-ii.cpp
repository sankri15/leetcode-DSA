#include <vector>
#include <algorithm>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;
        
        // Precompute the suffix minimums
        std::vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = std::min(suffix_min[i + 1], nums[i]);
        }
        
        // Iterate from left to right keeping track of the prefix maximum
        int current_max = nums[0];
        for (int i = 0; i < n; ++i) {
            current_max = std::max(current_max, nums[i]);
            
            if (current_max - suffix_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};