class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        // Base cases
        if (n <= 2) {
            return n;
        }
        // Find the next power of 2 strictly greater than n
        int ans = 1;
        while (ans <= n) {
            ans <<= 1; // Same as ans = ans * 2
        }
        return ans;
    }
};