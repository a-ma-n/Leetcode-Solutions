class Solution {
public:
    vector<int> countDigits(int N){
	vector<int>digitsInN(10);
	while(N)
		digitsInN[N % 10]++, N /= 10;
	return digitsInN;
}
    bool reorderedPowerOf2(int N) {
        // bf = rotate n check
        // find frequency of digits in all powers of 2 and then see if the given number has the sam  number of digits
	vector<int> digitsInN = countDigits(N); // freq of digits in N
        for(int i =0,powOf2 = 1 ; i < 30 ;i++, powOf2 <<=1)
            if(digitsInN == countDigits(powOf2)) return true;
        return false;
    }
};