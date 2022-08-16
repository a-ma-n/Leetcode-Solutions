class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        vector<vector<int>> ans;
        //if(iv.size()==0) return ans;
        sort(iv.begin(),iv.end());
        vector<int> temp = iv[0];
        for(auto it: iv){
            if(it[0]<=temp[1]){
                temp[1]=max(it[1],temp[1]);
            }
            else{
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};