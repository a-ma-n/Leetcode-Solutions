class Solution {
public:
    bool isSub(string s, string t, int m,int n){
        if( m == 0) 
            return true;
        if( n == 0 )
            return false;
        else{
            if(s[m-1] == t[n-1]){
                return  isSub( s,  t,  m-1, n-1);
            }
            
            return  isSub( s,  t,  m, n-1);
                
            
        }
    }
    
        
    
    bool isSubsequence(string s, string t) {
        
       int sizeSubstring = s.length(), sizeString = t.length();
        // A3 - Recursion
        // A4 - DP
        return isSub(s,t,sizeSubstring,sizeString);
         
        
        
        
        
    }
};











// A1 -> O(n^2)
//         for( i = 0 ; i < sizeSubstring ; ){
//             for( j = 0; j < sizeString ; j++){
//                 if( s[i] == t[j] ){
//                     i++;
//                 }
                
//             }
//             if(j==sizeString)
//                 break;
//         }
//
//         if(i==sizeSubstring){
//             return true;
//         }
//         else{
//             return false;
//         }

       
//    A2 -> unordered set
//
//    unordered_set <char> setLetters;
//         for( i = 0 ; i < sizeSubstring ; i++ ){
//             if( setLetters.find(s[i]) == setLetters.end() )
//                 setLetters.insert(s[i]);
//         }
        
//         int countLetters=0;
        
//         for( i = 0 ; i < sizeString ; i++ ){
//             if( s[countLetters] == t[i] )
//                 {
//                 // k++;
//                 countLetters++;
//             }
//         }
//         cout<<countLetters;
//        if(countLetters == sizeSubstring)
//            return true;
//         else
//             return false;