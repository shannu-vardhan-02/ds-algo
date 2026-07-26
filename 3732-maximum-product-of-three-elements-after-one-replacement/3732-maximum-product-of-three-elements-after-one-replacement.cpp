class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long max1 = 0;
        long long max2 = 0;
        
        for (int x : nums) {
            long long abs_x = abs(x);
            
            if (abs_x >= max1) {
                max2 = max1;
                max1 = abs_x;
            } else if (abs_x > max2) {
                max2 = abs_x;
            }
        }
        
        // multiply the two largest absolute values by 10^5
        return max1 * max2 * 100000LL;
    }
};