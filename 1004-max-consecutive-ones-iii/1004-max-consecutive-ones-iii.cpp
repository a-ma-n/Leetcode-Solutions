class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, maxi = 0 , j = 0 , N = nums.size(),cnt=0;
        for(;j<N;j++){
            if(nums[j]==0) cnt++;
            while(cnt>k)
                if(nums[i++]==0) cnt--;            
            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
};