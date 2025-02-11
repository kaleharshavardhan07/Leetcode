class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        // int i=0;
        // while(i< s.length()){
        //     if(s.length()<part.length()){
        //         break;
        //     }
        //     string temp=s.substr(i,part.length());
        //     if(temp==part){
        //         s.erase(i,part.length());
        //         if(i>0){
        //             i--;
        //         }
        //     }
        //     else{
        //         i++;
        //     }
        // } 
   while(s.length()>0 && s.length()>s.find(part)){
           s.erase(s.find(part),part.length());
        }
    return s;
        
    }
};