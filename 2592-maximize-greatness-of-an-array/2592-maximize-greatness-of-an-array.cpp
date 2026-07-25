class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        if(nums[0] == nums[n - 1]) return ans;
        int l = 0;
        int r = 0;
        while(r < n){
            while(r < n && nums[l] == nums[r]){
                r++;
            }
            if(r == n) return ans;
            if(nums[l] < nums[r]){
                ans++;
                l++;
                r++;
            }
        }
        return ans;
    }
};