class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> s;
        for(auto it:nums) s.push_back(it*it);
        sort(s.begin(),s.end());
        return s;
    }
};