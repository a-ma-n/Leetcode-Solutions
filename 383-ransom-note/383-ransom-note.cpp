class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> rm (26),mg(26);
        for(auto it :magazine) mg[it-97]++;
        for(auto it :ransomNote) rm[it-97]++;
        for(auto it:ransomNote) if(rm[it-97]>mg[it-97]) return false;
        return true;
    }
};