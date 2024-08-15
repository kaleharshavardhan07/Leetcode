class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int t=0;
        int f=0;
        int tw=0;
        for(int bill :bills){
            if(bill==5)f++;
            else if(bill==10){
                if(f>0){
                    f--;
                    t++;
                }
                else{return false;}
            }
            else if( bill==20){
                if(t>0 && f>0){
                    t--;
                    f--;
                    tw++;
                }
                else if(f>2){
                    f=f-3;
                    tw++;
                }
                else return false;
            }
        }
        return true;
    }
};