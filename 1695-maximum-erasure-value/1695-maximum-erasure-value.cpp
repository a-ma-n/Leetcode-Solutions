class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
         // unordered_set does not have contains() as it returns bool and info with find() and count() is              quite sufficient
        // contains works better with multiset and set
        unordered_set<int> hash;
        int start=0,end=0,sum=0,maxsum=0;
        for(end = 0;end<nums.size();end++){
            if(hash.count(nums[end])){
                while(start<end && hash.count(nums[end])){
                sum = sum - nums[start];
                hash.erase(nums[start]);
                start++;
                } 
            }
            sum += nums[end];
            maxsum = max(maxsum,sum);
            hash.insert(nums[end]);
        }
        return maxsum;
    }
};