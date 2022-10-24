class Solution {
public:
    int maxProfit(vector<int>& prices) {

// initially profit is zero, n is the length of the array of prices.
        int profit = 0, n = prices.size();
        // iterate over the array from index 1 to n-1
        for (int i=1; i<n; ++i) {
//assume that we already brought the shares
// if price of today is greater than yesterday, then profit should be increased
            if(prices[i] > prices[i-1])
// increase the profit  by adding today's profit in profit
// profit = today's price - yesterday's price
                profit += prices[i]-prices[i-1];
        }
        // return the total profit
        return profit;
    }
};