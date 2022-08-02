class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        set<int> count;
        vector<int> ans;
        vector<bool> in(n+1,0);
        for(auto a : edges){
            //int u = a[0];
            int v = a[1];
            //inout[u]--;
            in[v]=true;          
        }
        
        // as all the values of a & b start with 1 thus we start the loop with 1
        for(int i = 0 ; i < n ; i ++){
            if(!in[i]){
                //if(find (ans.begin(), ans.end(), i)==end(ans))  
                    count.insert(i);
            }
        }
        ans.resize(count.size());
        copy(count.begin(),count.end(),ans.begin());
        return ans;
    }
};