class Solution {
public:
    // 1) equal size
    // 2) min sum => min right + min left => in each min digit left max dig right
    int minimumSum(int num) {
        vector<int>v;
        string s=to_string(num);
        for(auto it:s) v.push_back(it-48);
        sort(v.begin(),v.end());
        return min( (v[0]*10+v[3])+(v[1]*10+v[2]),(v[1]*10+v[3])+(v[0]*10+v[2]));
    }
};