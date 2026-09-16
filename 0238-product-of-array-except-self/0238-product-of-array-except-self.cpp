class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int p = 1; // prefix product
        for(int i = 0; i < n; i++){
            ans[i] = p;
            p *= nums[i];
        }

        int s = 1; // suffix product
        for(int i = n - 1; i >= 0; i--){
            ans[i] *= s;
            s *= nums[i];
        }

        return ans;
    }
};