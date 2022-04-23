// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, comp);
        double curWeight = 0;
        double finalValue = 0.0;
        
        for(int i =0;i<n;i++){
            if(curWeight + arr[i].weight <= W){
                curWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            else{
                int remain = W - curWeight;
                finalValue += (arr[i].value/(double)arr[i].weight) * (double) remain;
                break;
            }
        }
        return finalValue;
    /*     double wt=0,v=0;
    //     vector<vector<double>> val;
    //     for(int i=0;i<n;i++){
    //         // 0-> wt, 1-> val , 2-> net
    //         val[i][0]=arr[i].weight;
    //         val[i][1]=arr[i].value;
    //         val[i][2]=arr[i].weight/arr[i].value;
    //     }
    //     // nlogn time
    //     // sorted in descending order of net val
    //     sort(val.begin(),val.end(),[&val](vector<int> a,vector<int> b ){
    //     return (a[2]<b[2]); // compare the net values
    // });
        
    //     for(int i=0;i<n;i++){
            
    //         if(wt>val[i][0]){
    //             wt+=val[i][0];
    //             v=val[i][1];
    //         }
    //         else{
                
    //             double fcost=0;
    //             fcost = ((W - wt)/val[i][0])*val[i][1];
    //             v+=fcost;
    //             // abg is full now
    //             break;
    //         }
            
    //     }
    //     return v;*/
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends