class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      
        vector<int> ans;
        set<int>s;
        // for(auto it:nums1){
        //     a.insert(it);
        // }
        // for(auto it:nums2){
        //     b.insert(it);
        // }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(auto it:nums2){
            if(bins(nums1,it)!=-1) s.insert(it);
        }
        for(auto it:s) ans.push_back(it);
        return ans;
    }
    int bins(vector<int> v,int target){
        int n=v.size();
        int high=n-1,low=0,mid;
        
        while(low<=high){
            mid=(low+high)/2;
            if(v[mid]==target) return mid;
            if(v[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};