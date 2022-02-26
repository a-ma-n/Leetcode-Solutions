class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res;
        map <int,char> mpp;
        for(int i=0;i<indices.size();i++){
           mpp.insert({indices[i],s[i]});
        }
        for(auto it:mpp){
            res=res+it.second;
        }
        return res;
    }
};