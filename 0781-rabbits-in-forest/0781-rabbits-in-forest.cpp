class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>mp;
        for( int i: answers)mp[i]++;
       int total=0;
        for (auto& p : mp)
        total += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
        return total;
    }
};