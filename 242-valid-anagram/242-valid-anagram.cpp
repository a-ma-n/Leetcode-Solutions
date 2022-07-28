class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>sm,tm;
        for(auto it : s){
            sm[it-97]++;
        }
        for(auto it : t){
            tm[it-97]++;
        }
        return sm==tm;
    }
};