#include<iostream>

using namespace std;

class Compressor{
   public:
   virtual void compress(const string &fileName)=0;
   virtual ~Compressor() {}
};

class JpegCompress:public Compressor{
   public:
     void compress (const string &filename)override {
      cout<<"Compress using jpeg\n";
   }
};

class PngCompress: public Compressor{
   public:
   void compress(const string &filename)override{
      cout<<"Compress using png\n";
   }
};

class Filter{
   public:
   virtual void filter(const string& filterName)=0;
   ~Filter(){}
};

class BlackAndWhite:public Filter{
   public:
   void filter(const string &fileName) override{
      cout<<"filter using B&W\n";
   }
};

class HighContrast:public Filter{
   public:
   void filter(const string &fileName) override{
      cout<<"filter using Highcontrast\n";
   }
};

class ImageStore
{
    public:
    ImageStore(){}
    void store (string fileName , Compressor* compressor ,Filter*filter )
    {
        compressor->compress(fileName);
        filter->filter(fileName);
    }

};

int main(){
  ImageStore*imageStore=new ImageStore();
  imageStore->store("a",new JpegCompress(), new HighContrast());

}
  