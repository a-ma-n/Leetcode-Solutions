/*
    Time Complexity: O(2 ^ N)
    Space Complexity: O(M),
    
    where N is the number of iterations and M is the length of the final string.
*/
class Solution {
public:
    string countAndSay(int n) {

    // We initialize our starting string s with "1".
    string s = "1";
    
    // We initialize the iterations with n-1.
    int iterations = n - 1;
    while (iterations--) 
    {
        // We will initialize temp with an empty string and we initialize count.
        string temp = "";
        vector<int> count;
        
        // currentIndex will store the current position in string s, currentChar will store the current character that we will match with consecutive characters.
        // And currentCount will store the count of that character.
        int currentIndex = 0;
        
        // Now we will iterate through s and we will try to make temp and count.
        while (currentIndex < s.length()) 
        {
            char currentChar = s[currentIndex];
            int currentCount = 0;
            while ((currentIndex < s.length()) && (s[currentIndex] == currentChar)) 
            {
                currentCount++;
                currentIndex++;
            }

            temp += currentChar;
            count.push_back(currentCount);
        }
        
        // Now we will make string s for the next iteration.
        // We will add count[i] and temp[i] to s for each position of count.
        s = "";
        for(int i = 0; i < count.size(); i++) 
        {
            s += (char)('0' + count[i]);
            s += temp[i];
        }
    }
    return s;
}
    
};