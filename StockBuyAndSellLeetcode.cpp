//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int m=prices[0];
        
        for(int i=0; i<prices.size(); i++)
        {
            m=min(m, prices[i]);
            profit=max(profit, prices[i]-m);
        }
        return profit;
    }
};
