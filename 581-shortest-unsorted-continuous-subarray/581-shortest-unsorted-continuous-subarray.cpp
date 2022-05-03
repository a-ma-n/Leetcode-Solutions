class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      
        int ans = 0;  
        
        // Two pointers
        int i = 0;
        int j = nums.size() - 1;

        int curr_max=INT_MAX;
        int curr_min=INT_MIN;
        
        // Initialize end to -1, if we have all sorted in ascending order, then end-start+1 = -1+0+1 = 0 
        int start=0,end=-1;
        
        while(j >= 0){
            // Check if the "num[start]" is greater than the minimum element so far
            if(nums[i] >= curr_min) curr_min = nums[i];
            else end = i; // m contains the 

            // Check if the "num[end]" is less than the maximum element so far
            if(nums[j] <= curr_max) curr_max = nums[j];
            else start = j;

            ++i;
            --j;
        }
        return end - start + 1;
    }
};

// [2,6,4,8,10,9,15]
// [1,2,3,4]
// [1]

  // int n=nums.size(),p1=0,p2=n-1,end1=0,end2=n-1;
  //       bool f1 = true,f2=true;
  //       while(end1<end2){
  //           if(nums[p1]<nums[p1+1])
  //           {
  //               if(f1) {p1++;
  //                      end1++;}
  //               cout<<"[p1]: "<<p1<<endl;
  //           }
  //           else if (nums[p1]==nums[p1+1]){
  //               end1++;
  //           }
  //           else{
  //               f1=false;
  //           }
  //           if(nums[p2]>nums[p2-1])
  //           {
  //               if(f2) {p2--;
  //                       end2--;};
  //               cout<<"[p2]: "<<p2<<endl;
  //           }
  //           else if(nums[p2]==nums[p2-1]){
  //               end2--;
  //           }
  //           else {
  //               f2=false;   
  //           }
  //           if(!f1 && !f2)
  //               break;
  //       } 
  //       return !f1?p2-p1+1:0;