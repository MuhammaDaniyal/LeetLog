class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int num;
        for (int i = 0; i < nums.size(); ++i)
        {
            num = target - nums[i];
            if (mp.find(num) != mp.end())
                return { mp[num], i };
            mp[nums[i]] = i;
        }
        return {};
    }
};