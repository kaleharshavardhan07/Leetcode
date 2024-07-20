class ParkingSystem {
    private:
   int ary[3];
public:
    ParkingSystem(int big, int medium, int small) {
         ary[0]=big;
         ary[1]=medium;
         ary[2]=small;}
    
    bool addCar(int carType) {
        if(carType>3 || carType<0){
            return false;
        }
        if(ary[carType-1]>0){
            ary[carType-1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */