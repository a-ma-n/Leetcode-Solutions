class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size(),sp=0;
      for(int i=0;i<n/2;i++){
          sp=s[i];
          s[i]=s[n-i-1];
          s[n-i-1]=sp;
      }  
    }
};