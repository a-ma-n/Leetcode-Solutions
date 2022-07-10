class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count=0,small=0,k=0;
        
        
        for(auto it:nums){
            if(it<target) small++;
            if(it==target) count++;
        }
        vector<int> result(count);
        for(int i = small;i<small+count;i++)
            result[k++]=i;
        
        return result;
    }
};