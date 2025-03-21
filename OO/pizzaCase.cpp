//Pizza
#include<bits/stdc++.h>
using namespace std;
class Pizza{
private:
void makeDough(){
    cout<<"Making "<<getPizzaName()<<"Dough"<<endl;
}
void bakePizza(){
     cout<<"Baking "<<getPizzaName()<<"pizza"<<endl;
}

protected:
virtual const char*getPizzaName()=0;
virtual void addToppings(){
    cout<<"Add tomato base"<<endl;
    cout<<"Adding cheese base"<<endl;
}
public:
void makePizza(){
    makeDough();
    bakePizza();
    addToppings();
    bakePizza();
    cout<<getPizzaName()<<"pizza is ready!"<<endl;
}
};

class ChickenPizza : public Pizza{
    protected:
    const char* getPizzaName(){
        return "Chicken";
    } 
    virtual void addToppings(){
        Pizza::addToppings();
        cout<<"Add "<<getPizzaName()<<" toppings"<<endl;
    }
};

class CheesePizza : public Pizza{
    protected:
    const char* getPizzaName(){
        return "Cheese";
    } 
};


class BeefPizza : public Pizza{
    protected:
    const char* getPizzaName(){
        return "Beef";
    } 
    virtual void addToppings(){
        Pizza::addToppings();
        cout<<"Add "<<getPizzaName()<<" toppings"<<endl;
    }
};
// Applying abstraction
void makePizza(Pizza*p){
    p->makePizza();
}
int main()
{
  int choice;
  cin>>choice;
    Pizza*p=NULL;
    switch(choice){
        case 1:
        // calls it's own addtoppings fuction
        p=new ChickenPizza;
        break;
        case 2:
        // call the parents'
        p=new CheesePizza;
        break;
        case 3:
        p= new BeefPizza;
        break;
        default:
        cout<<"incorrect choice "<<endl;
        return 1;
    }
    
    if (p != NULL) {
        makePizza(p); // Make the selected pizza
        delete p; // Clean up dynamically allocated memory
    }
}  
/*
Making ChickenDough
Baking Chickenpizza
Add tomato base
Adding cheese base
Adding toppings for Chickenpizza
Add Chicken toppings
Baking Chickenpizza
Chickenpizza is ready!
*/

/*
Making CheeseDough
Baking Cheesepizza
Add tomato base
Adding cheese base
Baking Cheesepizza
Cheesepizza is ready!
*/