class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n != 0) {
                        cout<<"n: "<<n;

            ans = ans + n % 2;
            n = n / 2;
            cout<<"ans: "<<ans<<endl;
        }
        return ans;
    }
};