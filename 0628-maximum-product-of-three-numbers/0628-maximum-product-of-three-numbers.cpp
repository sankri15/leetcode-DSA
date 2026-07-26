class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();

        int prod1 = nums[size - 1] * nums[size - 2] * nums[size - 3];
        int prod2 = nums[0] * nums[1] * nums[size - 1];
        
        return max(prod1, prod2);
    }
};