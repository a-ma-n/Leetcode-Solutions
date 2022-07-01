class Solution {
public:
    static bool cmp(vector<int> a ,vector<int> b){
        return a[1]>=b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int count=0,size=0;
        sort(boxTypes.begin(),boxTypes.end(),cmp);

        for(auto it: boxTypes){
            for(int j =1;j<=it[0];j++){
                if(truckSize==0)
                    break;
                count+=it[1];
                truckSize--;
            }
        }
        return count;
    }
};