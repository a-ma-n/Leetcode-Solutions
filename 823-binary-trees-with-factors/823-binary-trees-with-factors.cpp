class Solution {
    int mod = 1e9 + 7;
    unordered_map<int, long long int> dp;
    unordered_set<int> st;
private:
    long long int factorCount(int root)
    {
        // check in dp, if count has been calculated already for this root
        if(dp.count(root))
            return dp[root];
        
        // count = 1 , root element will also be our one of the ans
        long long int count = 1;
        
        // iterate through set
        for(auto &val : st)
        {
            // check if root is divisible or not
            if(root % val != 0) continue;
            
            // if its divisible, call recursively for its factor
            int factor1 = val, factor2 = root / val;
            
            // check its factor is present in given arr
            if(st.count(factor2))
            {
                count += factorCount(factor1) * factorCount(factor2);
                count %= mod;
            }
            
         }
        
        return dp[root] = count;
    }
    
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
                
        st.insert(arr.begin(), arr.end());
        
        int res = 0;
        
        for(auto &curVal : arr)
        {
            // check from root to leaf
            // make cur val as root and find its factors i.e leaves
            res += factorCount(curVal);
            res %= mod;
        }
        
        return res;
    }
};