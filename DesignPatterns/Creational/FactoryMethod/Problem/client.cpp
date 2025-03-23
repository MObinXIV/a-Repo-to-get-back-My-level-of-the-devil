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
/*
1- Singleton 
2- Factory method ✅ 
3- Observer 
4- Startegy
5- Decorator
6- Builder 
7- Adapter 
8- Facade 
*/   