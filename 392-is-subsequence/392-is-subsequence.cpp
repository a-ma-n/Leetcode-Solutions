class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int sizeSubstring = s.length(), sizeString = t.length(),i,j;
        
        // A1 -> O(n^2)
        // A2 -> unordered Hashmap
        
        for( i = 0 ; i < sizeSubstring ; ){
            for( j = 0; j < sizeString ; j++){
                if( s[i] == t[j] ){
                    i++;
                }
                
            }
            if(j==sizeString)
                break;
        }
        
        if(i==sizeSubstring){
            return true;
        }
        else{
            return false;
        }
       
    }
};