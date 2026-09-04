class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp = nums;
        for(int i = 1; i < n; i++){
            temp[i] = max(temp[i], temp[i - 1]);
        }
        
        int ans = -1; // stores the smallest stable idx

        int mini = temp[n - 1];
        for(int i = n - 1; i >= 0; i--){
            mini = min(mini, nums[i]);
            if(temp[i] - mini <= k) ans = i;
        }

        return ans;
    }
};