class Solution {
public:
    // store max profit
    int maxProfit(vector<int>& prices) {
        int profit = 0 , maxProf = 0 , n = prices.size(),minPrice = prices[0];  
        for(int i = 1 ; i < n ;  i ++ ){
            minPrice = min(minPrice,prices[i]);
            profit = prices[i] - minPrice;
            maxProf=max(maxProf,profit);
        }
        return maxProf;
    }
};