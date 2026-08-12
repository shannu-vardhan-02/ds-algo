class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> freq;
        for(int r = 0; r < n; r++){
            freq[nums[r]]++;

            while(freq[nums[r]] > k){
                freq[nums[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};