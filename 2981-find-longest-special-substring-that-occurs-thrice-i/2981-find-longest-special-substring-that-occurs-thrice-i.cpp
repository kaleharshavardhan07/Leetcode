class Solution {
public: set<string> generateSpecialSubstrings(string s) {
    set<string> specialSubstrings;
    
    // Iterate through the string
    for (int i = 0; i < s.length(); i++) {
        int count = 1;
        
        // Check consecutive same characters
        for (int j = i + 1; j < s.length(); j++) {
            // If characters are different, break
            if (s[j] != s[i]) break;
            
            // Increment count of consecutive same characters
            count++;
        }
        
        // Generate special substring for each possible length
        for (int len = 1; len <= count; len++) {
            // Create a special substring of current character repeated 'len' times
            specialSubstrings.insert(string(len, s[i]));
        }
    }
    
    // Return the set directly
    return specialSubstrings;
}
    int maximumLength(string s) {

       set<string> st=generateSpecialSubstrings( s);

        int maxi = -1;

        for (auto it : st) {
            int smax = 0;
            string temp = it;
            for (int i = 0; i < s.length() - temp.length() + 1; i++) {
                if (s.substr(i, temp.length()) == temp) {
                    smax++;
                }
            }
            if( smax>=3){
                int n=temp.length();
                maxi=max(maxi,n);
            }
        }
        if( maxi==0)return -1;
        return maxi;
    }
};