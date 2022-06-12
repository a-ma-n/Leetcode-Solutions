class Solution {
public:
    int romanToInt(string S) {
        int ans = 0, num = 0;
        int i = S.size()-1;
        // ~i => if i is 2 the ~i is -3 (-2 -1)
        for ( i = S.size()-1; ~i; i--) {
            cout<<"i"<<i<<"~i"<<~i<<endl;
            switch(S[i]) {
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
            }
            // subtract from the larger number
            if (4 * num < ans) ans -= num;
            else ans += num;
        }
        cout<<"i"<<i<<"~i"<<~i<<endl;
        return ans;        
    }
};