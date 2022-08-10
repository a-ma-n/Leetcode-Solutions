class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ;
    }
    
    int countVowelSubstrings(string s) {
      return atmost(s,5)-atmost(s,4);
    }
    int atmost(string s,int goal){
        int i = 0, j = 0 ,N =s.size(),ans=0;
      unordered_map<char,int> cnt;
      for(;j<N;++j){
          if(!isVowel(s[j])){
              cnt.clear();
              i=j+1;
              continue;
          }
          cnt[s[j]]++;
          while(cnt.size()>goal) {
              if(--cnt[s[i]]==0)
              cnt.erase(s[i]);
              ++i;
          }
          ans+=j-i+1;
      }
        
      return ans;
    }
};