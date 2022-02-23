class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //find repeated
        int dup=-1,act_sum=0,expected_sum,n=nums.size(),mis;
        for(auto it:nums){
            act_sum+=it;
        }
        for(int i=0;i<n;i++){
            auto val=abs(nums[i]);
            if(nums[val-1]<0)
            {   dup=val;
                break;
            }
            
            nums[val-1]*=-1;
        }
        
        expected_sum=(n*(n+1))/2;
        cout<<expected_sum<<endl;
        cout<<dup<<endl;
        cout<<act_sum<<endl;
        mis=expected_sum - act_sum   +dup;
        vector <int>v;
        v.push_back(dup);
        v.push_back(mis);
        return v;
    }
};