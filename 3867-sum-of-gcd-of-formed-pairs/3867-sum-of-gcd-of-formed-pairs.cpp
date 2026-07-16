class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            int hcf = gcd(mx, nums[i]);
            prefixGcd.push_back(hcf);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long sum = 0;
        for(int i = 0; i < (n/2); i++){
            sum += gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }
        return sum;
    }
};