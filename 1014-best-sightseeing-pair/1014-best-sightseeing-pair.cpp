class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res=0,cur=0;
        for(int a : A){
            res = max(res,cur+a);
            cur  = max(cur,a)-1; // at every step we subtract 1
        }
        return res;
    }
};