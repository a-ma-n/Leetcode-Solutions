class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> e,o;
        
        for(auto it:nums){
            if(it%2==0) e.push_back(it);
            else o.push_back(it);
        }
        e.insert( e.end(), o.begin(), o.end() );
        return e;
    }
};