class Solution {
public:
    int DecimalToBinary(int num)
{
    string str;
        vector <int>v;
        int c=0;
      while(num){
      if(num & 1) // 1
       { c++;
          str+='1';
       }
      else // 0
        str+='0';
      v.push_back(c);
      num>>=1; // Right Shift by 1 
    }   
      return c;
}
 
// int reverse(string str)
// {
//   for(int i=str.size()-1 ; i>=0 ; i--)
//   { 
//       cout<< str[i];
//   }
// }
    
    vector<int> countBits(int n) {
        vector<int> bitsV ;
        for(int i=0;i<=n;i++){
            bitsV.push_back(DecimalToBinary(i));
        }
        return bitsV;
    }
};