class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long ans = n*(n-1)/2;
        map<long long,long long> mp;
        for(int i =0;i<n;i++){
            mp[nums[i]-i]++;
        }
        for(auto m:mp){
            ans-= m.second*(m.second-1)/2;
        }
        return ans;
    }
};