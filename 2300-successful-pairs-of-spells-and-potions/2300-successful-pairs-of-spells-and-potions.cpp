class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long target) {
       
        sort(p.begin(), p.end());
        
        int n = s.size();
        int m = p.size();
        
        vector<int> v1;
        
        for(int i=0; i<n; i++){
            
            // req number
            long long req = target/s[i] + (target%s[i] != 0);
            auto it = lower_bound(p.begin(), p.end(), req);
            
            if(it == p.end())     v1.push_back(0);
            else{
                int ind = it - p.begin();
                v1.push_back(m-ind);
            }
        }
        return v1;}
        
};