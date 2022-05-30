class Solution {
public:
    	int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        bool isPositive = (dividend<0 == divisor<0);    // if both are of same sign, answer is positive
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while(a >= b){  // while dividend is greater than or equal to divisor
            short q = 0;
            while(a > (b<<(q+1)))
                q++;
            ans += (1<<q);  // add the power of 2 found to the answer
            a = a - (b<<q);  // reduce the dividend by divisor * power of 2 found
        }
        if(ans == (1<<31) and isPositive)   // if ans cannot be stored in signed int
            return INT_MAX;
        return isPositive ? ans : -ans;
    }
};


/*int divide(int dividend, int divisor) {
        bool f =false,end=false;
        if((dividend<0 && divisor<0)||(dividend>0 && divisor>0)){
            f=true;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        int temp=0;
        for(long i=1;;i++){
            if(i==2147483647){
                temp=i;   
                return !f?( (temp*-1)-1 ):temp;
                break;
            }
            if((((long)i*divisor )>dividend) ){
                return f?temp:temp*-1;
            }
                temp =i;
        }
        // if(!f){
        //     temp=temp*-1;
        //     return end?temp-1:temp;
        // }
        //     return temp;
    }*/