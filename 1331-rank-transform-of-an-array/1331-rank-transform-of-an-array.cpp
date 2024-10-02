class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>key;
        for( int n: arr){
            key.push_back(n);
        }
        sort( key.begin(),key.end());
        map<int,int>mapi;
int c=1;
        for( int i=0;i< key.size();i++){
            int temp=key[i];
            if( mapi.find(temp )!=mapi.end()){
              continue;
            }
            else{
            mapi[temp]=c++;}
        }
         for( int i=0;i< arr.size();i++){
            // int temp=arr[i];
            key[i]=mapi[arr[i]];
         }
       return key;
    }
};