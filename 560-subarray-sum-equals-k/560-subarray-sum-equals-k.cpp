class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // map to store the element count vs the number of times that values has appeared
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++; // increment the sum value 
        }
        return ans;
    }
};