class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int runningMin = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            runningMin = min(prices[i], runningMin);
            maxProfit = max(maxProfit, prices[i] - runningMin);
        }
        return maxProfit;
    }
};