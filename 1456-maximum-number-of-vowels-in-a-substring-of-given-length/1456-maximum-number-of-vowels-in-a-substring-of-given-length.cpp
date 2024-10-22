class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int>mp;
        int co=0;
        for( char c: s){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                co++;

            }
            mp.push_back(co);

        }
        int maxi=mp[k-1];

        for( int i=0;i<s.length()-k;i++){

            maxi=max(maxi,mp[i+k]-mp[i]);
            

        }
        return maxi;
         
    }
};