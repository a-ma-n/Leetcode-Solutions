class Solution {
public:
    // target - mid > 0  -> basically return the upper bound of the character
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0,high = letters.size(),mid;
        while(low<high){
            mid = low + (high-low)/2;
            
            if(letters[mid]<=target) low=mid+1;
            else high = mid;
        }
        // case if the element is not in sequence
        return letters[low%letters.size()];
    }
};