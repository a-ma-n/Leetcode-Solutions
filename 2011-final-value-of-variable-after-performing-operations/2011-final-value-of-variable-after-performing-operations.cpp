class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        // naive
        int x=0;
        for(auto op:operations){
            
                if(op[0]=='X'){
                    //postfix
                    if(op[1]=='-')
                        x--;
                    if(op[1]=='+')
                        x++;
                }else{
                //prefix
                   //postfix
                    if(op[1]=='-')
                        --x;
                    if(op[1]=='+')
                        ++x;
                 }
            
            }
        
     return x;
    }
};