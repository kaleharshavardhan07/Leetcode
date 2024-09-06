class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n=s.length();
        string r=s;

        for( int i=0;i<n;i++){
            int temp = (i+k)%n;
            
            r[i]=s[temp];
        }
        return r;
    }
};