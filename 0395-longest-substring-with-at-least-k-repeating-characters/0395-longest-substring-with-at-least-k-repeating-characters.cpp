class Solution {
public:
int solve( string & s, int start, int end, int k){
    if( end-start<k){
        return 0;
    }
    unordered_map<char,int>mapi;
    for( int i=start;i<end;i++){
        mapi[s[i]]++;
    }

    for( int i=start;i<end;i++){
        if( mapi[s[i]]<k){
            int r=solve(s,i+1,end,k);
            int l=solve( s, start,i,k);
            return max(r,l);
        }
    }
    return end-start;
}
    int longestSubstring(string s, int k) {
        return solve( s, 0, s.length(),k);
    }
};