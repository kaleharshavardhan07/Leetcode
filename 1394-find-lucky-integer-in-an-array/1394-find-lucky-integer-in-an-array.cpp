class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxif = 0;
        int got = -1;

        map<int, int> mp;
        for (int n : arr) {
            mp[n]++;
        }

        for( auto it : mp){
            if( it.first==it.second){
                if( maxif<it.second){
                    maxif=it.second;
                    got=it.first;
                }
                else if( maxif==it.second){
                    if( got<it.first){
                        got=it.first;;
                    }
                }
            }
        }
        return got;

    }
};