
#include<bits/stdc++.h>

using namespace std;
class Stream
{
    public:

   virtual void write(string data)=0;
};

class Cloud:public Stream{
   public:
    void write(string data) override{
      cout<<"Storing "<<data<<endl;
   }
};
class EncryptedCloudStream : public Stream
{

   private:
   Stream*stream;
   string encrypt(string data)
   {

       return "@&#@%#%****!";
   }

   public:

   EncryptedCloudStream(Stream*stream){this->stream=stream;}
   void write(string data) override
   {

       string lol = encrypt(data);

       stream->write(lol);
   }
   ~EncryptedCloudStream() {
    delete stream;  // Cleanup to prevent memory leaks
}
};
   
   
   class CompressedCloudStream :public Stream
   {
   private:
   Stream*stream;
       string compress(string data)
       {
   
           return data.substr(0,5);
       }
   
   public:
   CompressedCloudStream(Stream*stream){this->stream=stream;}
   void write(string data)override{
      string compressed=compress(data);
      stream->write(compressed);
   }    
   ~CompressedCloudStream() {
    delete stream;  // Cleanup to prevent memory leaks
}
   };
   // make it of type stream which is all 
   void storeCreditCard(Stream*stream){
      stream ->write("1242-24242-2332");
  }
int main()
{   
   storeCreditCard(new Cloud);

   storeCreditCard(new CompressedCloudStream(new Cloud));

   storeCreditCard(new EncryptedCloudStream(new Cloud));

   storeCreditCard(new EncryptedCloudStream(new CompressedCloudStream(new Cloud)));
}

