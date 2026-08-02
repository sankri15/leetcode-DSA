class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        multiset<long long> s;

        int i=0;
        int j=0;
        while(j<n){
            if(s.empty()){
                s.insert(nums[j]);
                j++;
                continue;
            }
            if(j>indexDiff){
                s.erase(s.find(nums[i]));
                i++;
            }

            auto temp = s.lower_bound((long long)nums[j]);

            if(temp!=s.end() && abs(*temp-nums[j])<=valueDiff)return true;
            if(temp!=s.begin() && abs(*(--temp)-nums[j])<=valueDiff)return true;
            s.insert(nums[j]);
            j++;
        }
        return false;
    }
};