#include<bits/stdc++.h>

using namespace std;

class Isubscriber{
   public:
   virtual void notify(string msg)=0;
};

class User: public Isubscriber{
   private:
   int userId;
   public:
   User(int userId){
      this->userId=userId;
   }

   void notify(string msg){
      cout<<"User "<< userId<<" recived message "<<endl;
   }
};

class Group{
   private:
   list <Isubscriber*>users;
   public:
   void subscirbe(Isubscriber*user)
      {
         users.push_back(user);}
   void unsubcribe(Isubscriber*user){
      users.remove(user);
   }   

   void notify(string msg){
      for(auto user : users)
      user->notify(msg);
   }
};

int main()
{   
   
  Group*group=new Group();
  User*user1=new User(1);
  User*user2 = new User(3);
  User*user3=new User(3);
  group->subscirbe(user1);
  group->subscirbe(user2);
  group->subscirbe(user3);
  group->notify("new message");

}
