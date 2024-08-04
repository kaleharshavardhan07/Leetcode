class Solution {
public:
    int maxPower(string s) {
        int count=1;
        int maxi=1;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                count++;
                maxi=max(maxi,count);
            }
            else{
                count=1;
                maxi=max(maxi,count);
            }
        }
        return maxi;
        
    }
};