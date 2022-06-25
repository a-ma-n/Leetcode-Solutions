class Solution {
public:
    string originalDigits(string s) {
        vector<int> mp(11);
        vector<int> storeCount(26,0);
        for(int i = 0;i<s.size();i++) storeCount[s[i] - 'a']++;
        mp[0] = storeCount['z'-'a'];
        mp[6] = storeCount['x'-'a'];
        mp[8] = storeCount['g'-'a'];
        mp[2] = storeCount['w'-'a'];
        mp[4] = storeCount['u'-'a'];
        mp[5] = storeCount['f'-'a'] - mp[4];
        mp[7] = storeCount['v'-'a'] - mp[5];
        mp[3] = storeCount['r'-'a'] - mp[4] - mp[0];
        mp[9] = storeCount['i'-'a'] - mp[8] - mp[6] - mp[5];
        mp[1] = storeCount['o'-'a'] - mp[4] - mp[2] - mp[0];
        string ans = "";
        for(int i = 0;i<mp.size();i++){
            while(mp[i]-- > 0) ans += to_string(i);
        }
        return ans;
    }
};