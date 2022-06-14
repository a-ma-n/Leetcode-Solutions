#define NO_OF_CHARS 256

class Solution {
public:
    bool isAnagram(string s, string t) {
       
    // Creating a hash array and initialising all the values as 0's
        int hash[NO_OF_CHARS] = { 0 };
        int i;
        
        int n1 = s.length();
        int n2 = t.length();
        
        // If length of both strings is not same, then they cannot be anagram.
        if( n1 != n2) return false;
        
        /*
       For each character in input strings, 
       increment count in the corresponding count array.
       and decrement the count in the anagram array
       */
        for( i = 0 ; i < n1 ; i++ ){
            hash[s[i]]++;
            hash[t[i]]--;
        }
        
        // check if all values are 0
        for( i=0 ; i< n1 ; i++){
            if(hash[s[i]] != 0){
                return false;
            }
        }
        return true;
    }
};