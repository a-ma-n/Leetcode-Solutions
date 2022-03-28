class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //1 -> rerotate the array
        //binary search
        vector<int> v;
        int breakPoint=0,i;
        bool f=false;
        for(i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                breakPoint=i+1;
                break;
            }
        }
        for(i=breakPoint;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        for(i=0;i<breakPoint;i++){
            v.push_back(nums[i]);
        }
        //show(v, nums.size());
         if (binary_search(v.begin(), v.begin() + nums.size(), target))
         {
             cout << "\nElement found in the array";
             f=true;
         }
    else
        cout << "\nElement not found in the array";
        return f;
    }
};