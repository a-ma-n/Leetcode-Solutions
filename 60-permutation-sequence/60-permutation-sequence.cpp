class Solution {
public:
    string getPermutation(int n,int k){
              int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
    }
};

//     int factorial(int n){
//         int f=1;
//         for(int i=1;i<=n;i++){
//             f*=i;
//         }
//         return f;
//     }
//     string getPermutation(int n, int k) {
//         int nfact=factorial(n-1);
//         int first=k/nfact;
//         int nthPermutation=k%nfact;
//         string s="";
//         int m=0;
//         if(k<=nfact){
//              m = first;
//              s = to_string(m)+"";
//         }
//         else{
//              m = first+1;
//              s=to_string(m)+"";
//         }
        
//         //cout<<"n is: "<<n<<endl;
//         if(n==1){
//             return "1";
//         }
//         for(int i=1;i<=n;i++){
//             if(i!=m){
//                 s=s+to_string(i);
//                 cout<<s;
//             }

//         }
//         int i;
        

    
        
//         for(i=1;i<nthPermutation;i++){    
//             next_permutation(s.begin(),
//                         s.end());
//         }
//         return s;
//     }
// };