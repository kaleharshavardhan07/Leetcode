// class Solution {
// public:
//     string reverseVowels(string s) {
//         int k= s.length();
//         vector<char>vowel;
//         for(int i=0; i<k;i++){
//             if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
//                 char key=s[i];
//                    vowel.push_back(key);
//             }
//         }
//          for(int i=0; i<k;i++){
//             if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
//                char in = vowel.back();
//                s[i]=in;
//                vowel.pop_back();
//             }
//         }
//     return s;
//     }
// };


class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        while (left < right) {
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};
