class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);
        int maxSize=0,count=0;
        for(int i=0;i<nums.size();i++){
           
            if(nums[i]==0){
                if(maxSize<count){
                    maxSize=count;
                }
                count=0;
            }
            
            if(nums[i]==1 ){
                count++;
            }
        }
        return maxSize;
    }
};