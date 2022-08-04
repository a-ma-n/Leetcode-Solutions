class Solution {
public:
    bool isRobotBounded(string instructions) {
        int top=0,right=0,count=0;
        bool flag=false;
        //int D = {N,E,S,W}
        //       0  1  2  3
        //count%4
        //.      0 -3 -2 -1
        // G -> increment 
        // L -> count --
        // R -> count ++
        for(auto it:instructions){
            flag=false;
            switch (it){
                case 'G':
                    flag=true;
                    break;
                case 'L':
                    count--;
                    break;
                case 'R':
                    count++;
                    break; 
            }
            // cartesian -> inc
            //            ^inc
            if(flag){
                if(count%4==0) top++;
                if(count%4==1 || count%4==-3) right++;
                if(count%4==2 || count%4==-2) top--;
                if(count%4==3 || count%4==-1) right--;
            }
        }
        
        return (!top && !right) || count%4!=0 ;
    }
};