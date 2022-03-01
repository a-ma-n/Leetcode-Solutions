class Solution {
public:
//     int DecimalToBinary(int num)
// {
//     string str;
//         vector <int>v;
//         int c=0;
//       while(num){
//       if(num & 1) // 1
//        { c++;
//           str+='1';
//        }
//       else // 0
//         str+='0';
//       v.push_back(c);
//       num>>=1; // Right Shift by 1 
//     }   
//       return c;
// }
 
    vector<int> countBits(int n) {
        vector<int> res(n);
        res.push_back(0);//for 0th element
        if(n==0)
            return res;
        
        for(int i=1;i<=n;i++){
            if(i%2==0)
                res[i]=res[i/2];
            else 
                res[i]=res[i-1]+1;
        }
        return res;
    }
};