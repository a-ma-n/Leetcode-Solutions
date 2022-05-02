class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int p1=0,p2,n=nums.size(),sw=0;
        p2=n-1;
        while(p1<p2){
            
           if (nums[p1]%2 > nums[p2]%2){  // p1-> has odd & p2-> has even => swap then fas fas
                sw = nums[p1];
                nums[p1] = nums[p2];
                nums[p2] = sw;    
            }
            
            if(nums[p1]%2==0 ) p1++;
           
            if(nums[p2]%2!=0 ) p2--;
            

             

            
  
            
        }
        
        return nums;
    }
};

// [3,1,2,4]
// [0]
// [1,0,3]