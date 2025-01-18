class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0, size = nums.size();

        for (int i = 0; i < size; ++i)
        {
            if (!j || nums[j - 1] < nums[i])
                nums[j++] = nums[i];
        }
        return j;
    }
};