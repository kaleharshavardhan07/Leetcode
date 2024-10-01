class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            vector<int>freq(26,0);
            for(int j=i;j<s.length();j++){
                freq[s[j]-'a']++;
                int maxi=0;
                int mini=1000;
                for(int i=0;i<26;i++){
                    if(freq[i]>0)mini=min(mini,freq[i]);
                    maxi=max(maxi,freq[i]);
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};