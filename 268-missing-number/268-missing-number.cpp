class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),sum=(n*(n+1))/2;
        // edge case: can also have zero missing
        for(int i=0;i<n;i++){
            sum-=nums[i];
            //cout<<"Remaininfg sum"<<sum<<endl;
        }
        if(sum == (n*(n+1))/2 & n!=1)
            return 0;
        else 
            return sum;
        
    }
};

