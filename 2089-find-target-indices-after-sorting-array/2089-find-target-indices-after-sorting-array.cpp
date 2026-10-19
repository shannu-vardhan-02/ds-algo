class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int tCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < target) count++;
            if(nums[i] == target) tCount++;
        }
        vector<int> ans;
        for(int i = 0; i < tCount; i++){
            ans.push_back(count + i);
        }
        return ans;
    }
};