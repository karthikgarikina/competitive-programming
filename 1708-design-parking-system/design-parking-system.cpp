class ParkingSystem {
private:
int space[4];    
public:
    ParkingSystem(int big, int medium, int small) {
        space[1]=big,space[2]=medium,space[3]=small;
    }
    
    bool addCar(int carType) {
        space[carType]--;
        return space[carType]>=0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */