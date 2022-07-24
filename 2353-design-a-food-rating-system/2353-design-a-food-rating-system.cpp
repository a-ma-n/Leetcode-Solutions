#include <type_traits>
class FoodRatings {
public:
 
    map<string,set<pair<int,string>>>mp;
    map<string,pair<string,int>>mp1;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        mp.clear();
        mp1.clear();
        for(int i=0;i<foods.size();i++)
        {
            string a = foods[i];
            string b = cuisines[i];
            int c = ratings[i];
            mp1[a]={b,c};
            mp[b].insert({c,a});
        }
    }
    
    void changeRating(string food, int newRating) {
        string a = mp1[food].first;
        int b = mp1[food].second;
       
        mp[a].erase({b,food});
        mp[a].insert({newRating,food});
        mp1[food]={a,newRating};
    }
    
    string highestRated(string cuisine) {

        auto s1 = (mp[cuisine].end());
        s1--;
        int s = s1->first;
        auto it = mp[cuisine].lower_bound({s,"a"});
        return it->second;
    }
};