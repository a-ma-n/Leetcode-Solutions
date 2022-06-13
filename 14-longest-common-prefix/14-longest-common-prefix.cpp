/*
    Time Complexity: O(M*N*log(M))
    Space Complexity: O(M)
*/
#include <climits>

class Solution {
public:
    // A function to check whether string prefix is common in all strings or not.

    bool isCommon(vector<string> &arr, string &prefix, int length, int n)
{
    for(int idx = 0; idx < length; ++idx)
    {
        for(int index = 0; index < n; index++)
        {
            // If arr[index][idx] is not equal to prefix[idx], return false.
            if (arr[index][idx] != prefix[idx])
            {
                return false;
            }
        }
    }
    
    // The string prefix is common in all strings.
    return true; 
}
    
string longestCommonPrefix(vector<string> &arr)
{
    int n = arr.size();
    // The string prefix to store the shortest string.
    string prefix = "";

    // The variable minlength to store the length of the shortest string.
    int minLength = INT_MAX;

    for(int index = 0;index < n; ++index)
    {
        if (arr[index].size() < minLength)
        {
            minLength = arr[index].size();
            prefix = arr[index];
        }
    }

    int start = 0;
    int end = minLength;
    int mid;

    while (start <= end)
    {   
        mid = (start + end) / 2;

        // The substring prefix of length mid is common in all strings 
        if (isCommon(arr, prefix, mid, n))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    mid = (start + end) / 2;

    // The string answer will store the longest common prefix 
    string answer = prefix.substr(0, mid);

    return answer;
}
};