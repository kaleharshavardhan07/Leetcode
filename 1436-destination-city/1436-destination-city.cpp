class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
         map<string,int>mapi;
     for(int i=0;i<paths.size();i++){
            mapi[paths[i][0]]++;
            mapi[paths[i][1]]--;


        }
        for(auto it :mapi){
            if(it.second<0){
                return it.first;
            }
        }
        return "";


    }
};