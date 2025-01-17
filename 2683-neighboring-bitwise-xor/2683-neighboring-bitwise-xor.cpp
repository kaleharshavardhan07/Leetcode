class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int c=0;
        for(int a: derived){
            c=c^a;
        }

        if(c==0)return true;
        return false;

    }
};