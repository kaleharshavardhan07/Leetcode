class Solution {
public:
    int titleToNumber(string columnTitle) {
        int tot=0;
        int t=columnTitle.length()-1;
        for( char c: columnTitle ){
            int temp=1;
               for( int i=0;i<t;i++){
                    temp=temp*26;
               }
              int k=int(c-'A')+1;
               tot=tot +( temp*k);
               t--;

        }
        return tot;
    }
};