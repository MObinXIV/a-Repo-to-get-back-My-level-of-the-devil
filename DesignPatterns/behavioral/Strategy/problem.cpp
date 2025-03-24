#include<iostream>

using namespace std;

class ImageStore
{

    private:
    string compressor;
    string filter;
    public:

    ImageStore(string compressor , string filter)
    {
        this->compressor=compressor;
        this->filter=filter;
    }
    void store (string fileName)
    {
        if (compressor=="jpeg")

        cout <<"compressing using jpeg\n";

        else if (compressor== "png")

        cout<<"Compressing using png\n";


    if (filter=="b&w")

        cout <<"Applying B&W filter\n";

        else if (filter== "high contrast")

        cout<<"Applying High contrast filter\n";

    }
};

int main(){
    ImageStore image("jpeg","b&w");
    image.store("a");
 }