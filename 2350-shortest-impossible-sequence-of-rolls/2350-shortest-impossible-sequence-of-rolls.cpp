class Solution {
    // we need to find shortest seq can tbe taken from rolls, find all shortest possible subsequences
    // and take [1,2,3,4,3,2,1]
public:
    int shortestSequence(vector<int>& A, int k) {
        int res = 1;
        unordered_set<int> s;
        for (int& a : A) {
            s.insert(a);
            if (s.size() == k) {
                res++;
                s.clear();
            }
        }
        return res;
    }
};