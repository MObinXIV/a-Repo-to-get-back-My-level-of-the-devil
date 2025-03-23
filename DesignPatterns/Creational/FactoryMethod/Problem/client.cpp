#include<bits/stdc++.h>
using namespace std;
#include "car.hpp"
#include "bike.hpp"

int main()
{   
   string vehicleType;
   Vehicle*vehcile;
   cout <<"enter the vehicle type \n";
   cin>>vehicleType;
   if(vehicleType=="car")
   vehcile=new Car();
   else if (vehicleType=="bike") vehcile = new Bike();
   vehcile->createVehicle();
}
