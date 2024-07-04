class Solution {
public:
    bool ispali(string& s) {
        int l = 0;
        int r = s.length() - 1;
        while (r > l) {
            if (s[r] != s[l]) {
                return false;
            }

            l++;
            r--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for( string s : words){
            if(ispali(s)){
                return s;
            }
        }
        return "";
    }
};