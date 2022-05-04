class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        
        // count frequency of num
        for(auto &num:nums) mp[num]++;
        
        int ans = 0;
        
        for(auto it = mp.begin();it!=mp.end();++it){
            
            int num = it->first, count = it->second;
            
            if(k-num == num) ans += count/2;   // if num is half of k add half of it's count in ans
            
            else if(mp.count(k-num)){
                
                // as say k=5, then we have 2->2 , 3->1 then min will be 1 (minimum)
                 int Min = min(count, mp[k-num]);
                
                ans += Min;
                mp[num] -= Min;
                mp[k-num] -= Min;
                
            }
            
        }
        
        return ans;
    }
};