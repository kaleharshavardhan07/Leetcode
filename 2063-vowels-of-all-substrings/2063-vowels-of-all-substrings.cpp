class Solution {
public:
    long long countVowels(string word) {
        long long count=0;
        long long left=0;
        long long r=word.length();
        long long vowel=0;

        for( long long i=0;i<r;i++){
            if(word[i]=='a'|| word[i]=='e'|| word[i]=='o'|| word[i]=='i'|| word[i]=='u'){
               count += (i + 1) * (r - i);
            }
          
        }
        return count;

    }
};