class Solution {
public:
    
    
    string simplifyPath(string path) {
        int n = path.length();
        stack<string> s;
        if(path[n-1]!='/'){
            path+="/",++n;
        }
        int i=1;
        string ans = "";
        string temp ="";
        
        while(i<n){
            if(path[i]=='/'){
                if(temp=="" || temp=="."){
                    //ignore
                }
                else if(temp == ".."){
                    if(!s.empty())
                        s.pop();
                }
                else{
                    s.push(temp);
                }
                temp ="";
            }
            else{
                temp.push_back(path[i]);
            }
            ++i;
        }
        while(!s.empty()){
            ans="/"+s.top()+ans;
            s.pop();
        }
        
              if(ans.length()==0)
                ans="/";
              
              return ans;
    }
};



  
//     string remDoubleSlash(string s){
        
//         char c1=' ',c2=' ';
//         int n =s.length();

//     for(int i=0;i<s.length();i++){
//             c1=s[i];
//             c2=s[i+1];
            
//             if(c1==c2 && c1=='/' )
//                {
//                    // append the rest of the string removing the /
//                    s = s.substr(0,i+1)+s.substr(i+2,n-1 -i );
//                    i++;
//                }
               
//         }
//                return s;
//     }             
//     string remDoubleDot(string s){
//         char c1=' ',c2=' ';
        
//         string prevDirectory="/";
//         string newDirectory="";
        
//         int n =s.length();
//         bool foundDIr= false;
//         for(int i =0;i<s.length()-1;i++){
//             c1=s[i];
//             c2=s[i+1];
//             if()
            
//             if(c1==c2 && c1=='.'){
//                 //TODO: change to prev directory -> store it if you find / => switch to last directory
//                 f=true;
//                 s = s.substr(0,i+1)+s.substr(i+2,n-1 -i );
//                 i++;
//             }
//             if(f){
                
//                 // remove the .. part with the previous directory 
//             }
//         }
//         return s;
//     }
//     string remTrail(string s){
//         int n =s.length();

//         while(s[s.length()-1] =='/' && s.length() >1 ){
            
//               s=s.substr(0,s.length()-1);
//               }
//               return s;
//     }        
             
// a-> no trail slash -> check last char in a loop
        // b-> no double slash -> replace with single / => maintain 2 ptrs
        // c-> .. means refer 1 directory up -> store the previous directory stating with /
        
    //     string prev="/";
    //     int i,n=path.length();
    //     if(n ==0){ // => single /
    //         return path;
    //     }
    //     path = remDoubleSlash(path);
    //     path = remDoubleDot(path);
    //     path = remTrail(path);
    //     return path;
    // }