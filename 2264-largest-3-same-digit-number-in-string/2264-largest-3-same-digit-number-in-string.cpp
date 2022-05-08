class Solution {
public:
     string largestGoodInteger(string num) {
        int i,n=num.length(),m=0,max=-1;
        string w="",word="";
        for(i=0;i<n-2;i++){
            w=num.substr(i,3);
            m=stoi(w);
            if(w[0]==w[1]&&w[1]==w[2]){
                // same digit no
                if(m>max){
                    max=m;
                    word=w;
                    cout<<"\nword is"<<word;
                }
            }
        }
        
        return (m > -1)?(word):"";
    }
    
    
    
};