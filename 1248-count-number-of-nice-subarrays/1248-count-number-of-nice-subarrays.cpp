class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int>& nums, int k){
        int i=0, maxi = 0 , j = 0 , N = nums.size(),cnt=0,count=0;
        for(;j<N;j++){
            if(nums[j]%2!=0) cnt++;
            while(cnt>k)
                if(nums[i++]%2!=0) cnt--;  
            //maxi = max(maxi,j-i+1);
            count+=j-i+1;
            //cout<<count<<endl;
        }
        return count;
    }
};