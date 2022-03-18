class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0],pr=0,i,p,current_profit=0,max_profit=0;
        for(auto it:prices){
            
            if(min>it){
                min=it;
            }
            current_profit=it-min;
            if(current_profit>max_profit){
                max_profit=current_profit;
            }
        }
        return max_profit;
    }
};