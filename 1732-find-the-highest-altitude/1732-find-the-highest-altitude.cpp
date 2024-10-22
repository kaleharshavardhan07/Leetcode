class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int c=0;
        int cc=0;
        for(int n:gain){
            c=c+n;
            cc=max(cc,c);
        }
        return cc;
    }
};