class Solution {
public:
    
    // TC: O(N)
    // SC: O(1) ~ O(5)
    int maxProfit(vector<int>& prices) {
        int i = 0, buy , sell , profit = 0 ,N = prices.size() - 1;
        while(i < N){
            while( i < N && prices[i+1] <= prices[i] ) i++; // store the minimum in succesive elements
            buy = prices[i];
            
            while( i < N && prices[i+1] > prices[i] ) i++; // store maximum in successive elements
            sell = prices[i];
            
            profit += sell - buy; 
        }
        return profit;
    }
    
};