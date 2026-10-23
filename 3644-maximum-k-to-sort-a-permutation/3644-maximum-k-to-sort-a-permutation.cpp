class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;                       // all bits set (AND identity)
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {             // misplaced element must be swapped
                ans &= nums[i];             // k must be a submask of it
            }
        }
        return ans == -1 ? 0 : ans;         // already sorted -> 0
    }
};