#include<bits/stdc++.h>
using namespace std;
#include "vehicle_factory.hpp"

// Now if I add any new vehicle it handles inside the factory method 
int main()
{   
   string vehicleType;
   cout <<"enter the vehicle type \n";
   cin>>vehicleType;
   Vehicle*vehicle = VehicleFactory::getVehicle(vehicleType);
   vehicle->createVehicle();
   
}
