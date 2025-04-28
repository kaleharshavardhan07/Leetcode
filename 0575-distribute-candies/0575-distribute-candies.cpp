class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>s;
        for( int n:candyType )  s.insert(n);
        int t=(candyType.size()/2);
        if( t>s.size())return s.size();
        return t;
    }
};