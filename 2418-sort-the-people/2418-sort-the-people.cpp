class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        map< int,string>mapi;
        for(int i=0;i<names.size();i++){
            mapi[heights[i]]=names[i];

        }
        int count=0;
        for (auto it = mapi.rbegin(); it != mapi.rend(); ++it){
            names[count]=it->second;
          count++;
            
        }
        return names;



    }
};