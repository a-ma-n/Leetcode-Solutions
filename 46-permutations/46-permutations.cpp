class Solution {
public:
    void recurPermute(int index,vector<int> &nums, vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            recurPermute(index+1,nums,ans);
            swap(nums[index],nums[i]); // backtracking to replacen the value of the swapped variable
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0,nums,ans);
        return ans;
    }
};