class Solution {
public:
  vector<vector<int>> generate(int n) {      
   vector<vector<int>> r(n); 
      for(int i =0;i<n;i++){
          r[i] = vector<int>(i+1,1);        
          for(int j =1;j<i;j++) // i<n && j<i => so last element isskipped
              r[i][j]=r[i-1][j]+r[i-1][j-1];
    }
  return r;
  }    
};