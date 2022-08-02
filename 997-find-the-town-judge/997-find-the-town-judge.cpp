class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // instead of takimg 2 arrays of indegree & outdegree,we take 1 array where we add 1 when there is a indegree and subtract 1 when there is an outdegree. Now node having n-1 indegree & 0 outdegree is the answer
        vector<int> inout(n+1,0);
        for(auto a : trust){
            int u = a[0];
            int v = a[1];
            inout[u]--;
            inout[v]++;          
        }
        // as all the values of a & b start with 1 thus we start the loop with 1
        for(int i = 1 ; i <= n ; i ++){
            if(inout[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};