class Solution {
public:
    int possibleStringCount(string word) {
     
        int n= word.size();
        if( n==1)return 1;
        unordered_set<string>res;
        res.insert(word);
        
        for( int i=0;i<n;){
            int j=i+1;
            while( j<n && word[j]==word[i]){
                j++;
            }
            if( j>i+1){
                for( int k=i+1;k<j;k++){
                    string news=word.substr(0,k)+word.substr(j);
                    res.insert(news);
                }
            }
            i=j;
        }
        return res.size();
    }
};