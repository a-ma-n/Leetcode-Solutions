class Solution {
public:
    vector<int> countFreq(string &s){
        vector<int> freq(26);
        for(auto c:s)
            freq[c-'a']++;
        return freq;
    }
    vector<string> wordSubsets(vector<string>& word1, vector<string>& word2) {
        vector<int>maxFreq(26);
        vector<string>ans;        
        
        for(auto& word:word2){
            vector<int> freq = countFreq(word);
            for(int i=0;i<26;i++) maxFreq[i]=max(maxFreq[i],freq[i]);
        }
        
        for(auto& w:word1 ){
            vector<int> freq = countFreq(w);
            int i= 0;
            for(;i<26;i++) if(freq[i]<maxFreq[i]) break;
            if(i==26) ans.push_back(w);            
        }
        
        return ans;
    }
};