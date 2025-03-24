// The adapter pattern converts the interface of class into another interface of the clients expect.
// allow incomptable interfaces to be comptable with each other
#include<bits/stdc++.h>

using namespace std;

class Cloud{
   public:
   virtual void write(string data){
      cout<<"Storing "<<data<<endl;
   }
};
class EncryptedCloudStream : public Cloud{

   private:
   
   string Encyrpt(string data){
   
   return "@&#@%#%****!";
   }
   
       public:
   
       void write (string data) override{
   
            string lol =Encyrpt(data);
   
           Cloud::write(lol);
       }
   };
   
   
   class CompressedCloudStream :public Cloud
   {
   private:
       string compress(string data)
       {
   
           return data.substr(0,5);
       }
   
   public:
       void write(string data) override
       {
   
           string lol = compress(data);
   
           Cloud::write(lol);
       }
   };

   class CompressedAndEncryptedData  : public Cloud{
      /*
      blablabla
      */
      };
