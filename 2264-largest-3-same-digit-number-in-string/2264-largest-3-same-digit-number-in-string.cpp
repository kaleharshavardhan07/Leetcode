class Solution {
public:
    string largestGoodInteger(string num) {
        string maxi = "-1";
        for (int i = 1; i < num.length() - 1; i++) {

           if (num[i] == num[i - 1] && num[i] == num[i + 1]) {
                string triple(3, num[i]); 
                if (triple > maxi) {
                    maxi = triple;
                }
            }
        }
        if( maxi=="-1")return "";
        return maxi;
    }
};