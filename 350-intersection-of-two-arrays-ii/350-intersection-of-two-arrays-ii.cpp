class Solution {
public:
    // Take smaller array iterate through it and then bin s for that element in the other array and append the ans 
    // Time Complexity O(NlogN)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
        
       vector<int> ans;
       vector<int> &a = nums2;
       int initL = 0 ;
        
        for(auto &t : nums1 ){
            int n = a.size(),L = initL , R =n-1;
            while(L<=R){
                int M = L +(R-L);
                // M-1<initL ?
                if( (M-1<initL || a[M-1]<t) && a[M] == t ) {

                    // int M = L + (R-L)/2;
                    ans.push_back(t);
                    initL = M+1;
                    break;
                }
                    
                if(t<=a[M]) R=M-1; else L=M+1;
            }
        }
        return ans;
    }
};