class Solution {
public:
    int numberOfSteps(int num) {
        int c=0;
        while(num>0){
            if(num%2==0)
                c++;
            else if(num==1)
                c++;
            else
                c+=2;
            num/=2;
            cout<<num<<endl;
        }
        return c;
    }
};