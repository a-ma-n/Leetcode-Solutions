/*
    Time Complexity : O(N ^ 2)
    Space Complexity: O(1)
    
    Where N is the length of the string.
*/

#include <algorithm>
class Solution {
public:
    int expandAroundCenter(string str, int left, int right) 
{
    int start = left, end = right;
    int n = str.length();

    // Expand the center.
    while (start >= 0 && end < n && str[start] == str[end]) 
    {
        start--;
        end++;
    }

    return end - start - 1;
}
    string longestPalindrome(string str) {
        int n = str.length();

    if (n < 1) 
    {
        return "";
    }

    int start = 0, end = 0;

    for (int i = 0; i < n; i++) 
    {
        // Longest odd length palindrome with center points as i.
        int len1 = expandAroundCenter(str, i, i);

        // Longest even length palindrome with center points as i and i + 1.
        int len2 = expandAroundCenter(str, i, i + 1);
                
            int len = max(len1,len2);
        
        
        // Update the start and end.
        if( len > end - start + 1){
            start = i - (len - 1)/2;
            end = i + (len)/2;
            }
        }
        
        return str.substr(start, end - start + 1);
    }
};