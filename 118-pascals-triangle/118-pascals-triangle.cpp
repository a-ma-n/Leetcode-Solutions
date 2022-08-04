class Solution {
public:
  vector<vector<int>> generate(int n) {      
    vector<vector<int>> v(n);
       for(int i = 0 ; i < n ;i++ ){
           v[i]= vector<int>(i+1,1);
           for(int j = 1 ; j < i; j++ )
               v[i][j] = v[i-1][j]+v[i-1][j-1];
       }
      return v;
  }
};