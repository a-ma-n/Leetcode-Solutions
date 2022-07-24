class Solution {
public:
    // This part will be executed for odd strings , where there is a character in the middle which needs to be checked
    bool isPalindrome(string &s,int i,int j){ 
        while(i<j && s[i]==s[j])
            ++i,--j;
        // if pointers succesfully crossed each other (last element is also satisfying thec condition) / are equal(i==j) => a mid != b mid , but a mid -> is palindrome
        cout<<i<<" "<<j;
        return i>=j;
    }
    bool check(string &a,string &b){
        int i = 0 , j = a.size()-1 ;
        // |
        // v..>
        // ula | cfd
        // jiz | alu
        //      <..^
        //         |
        while(i<j && a[i]==b[j])
            ++i,--j;
        // v
        // c f d
        //.    ^
        
        return isPalindrome(a,i,j) || isPalindrome(b,i,j);
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a,b) || check(b,a);
    }
};