class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector <string>v;
        for(auto p(0),q(0);q<nums.size();q++){ 
            if(q+1==size(nums) || nums[q]+1 != nums[q+1]){ //1st case is edge case as for the last element in order wo dont have q!=q1 so we need to print the last element      
                v.push_back(p!=q?
                              (to_string(nums[p])+"->"+to_string(nums[q])):
                              (to_string(nums[p]))
                              );   
                p=q+1;
            }
            
    }
        
        //cout<<"final l:"<<l<<"final r:"<<r;
        
//         if(l==r){
//             // nums[i-1];
//             //cout<<
            
//              str = to_string(nums[r]);
//             cout<<str;
//             v.push_back(str);
//         }
          
        return v;
    }
};