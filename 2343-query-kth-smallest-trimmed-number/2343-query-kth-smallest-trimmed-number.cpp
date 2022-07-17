#define p pair<string,int>
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        int sz=q.size();
        vector<int>ans;
        
        //iterate through each query
        for(auto & vec:q){
            // k,trim are variables used in question
            int k=vec[0],trim=vec[1];
            vector<p>arr;
            int i=0;
            for(auto & num:nums){
                // substring that we want is from startIdx to last Idx
                int startIdx=num.size()-trim,lastIdx=nums.size();
                // to remove leading zeros
                while(startIdx<lastIdx && num[startIdx]=='0')
                    startIdx++;
                arr.push_back({num.substr(startIdx),i});
                i++;
            }
            // std::nth_element()   rearranges the list in such a way such that the element at the nth position is the one which should be at that position if we sort the list.
            nth_element(begin(arr),begin(arr)+k-1,end(arr),[&](auto&a,auto&b){
                auto& [s1,idx1]=a;auto &[s2,idx2]=b;
                // if two string are equal then sort according to their indexes
                if(s1==s2)
                    return idx1<idx2;
                // if size is equal then just compare two strings
                if(s1.size()==s2.size())
                    return s1<s2;
                // if size is not equal then string with smaller length is smaller number then other one
                else
                    return s1.size()<s2.size();
            });
            ans.push_back(arr[k-1].second);
        }
        return ans;
        
    }
};
