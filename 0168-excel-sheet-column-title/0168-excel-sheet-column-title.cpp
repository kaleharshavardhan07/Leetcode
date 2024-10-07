class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
        while( columnNumber>0){
            columnNumber--;
            int temp=columnNumber%26;
            s=char(temp+'A')+s;
            columnNumber=columnNumber/26;
        }
        return s;

    }
};