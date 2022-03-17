class Solution {
public:
    vector<string> cellsInRange(string s) {
        int c1=(int)(s[0]),c2=(int)(s[3]),r1=(int)s[1]-48,r2=(int)s[4]-48;
        cout<<c1<<endl;
        cout<<c2<<endl;
        vector <string> v;
        string w="";
        int k=r1;
        for(;c1<=c2;c1++){
            for(k=r1;k<=r2;k++ ){
                w=w+(char)c1+(char)(k+48);
                cout<<"cout is:"<<(char)k<<endl;
                v.push_back(w);
                w="";
            }
        }
        return v;
    }
};