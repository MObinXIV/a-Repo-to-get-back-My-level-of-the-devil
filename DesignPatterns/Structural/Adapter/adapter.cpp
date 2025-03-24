// The adapter pattern converts the interface of class into another interface of the clients expect.
// allow incomptable interfaces to be comptable with each other
#include<iostream>

using namespace std;

class XmlData{
   string xmlData;

   public:

   XmlData(string xmlData){
       this->xmlData=xmlData;
   }

   string getXmlData(){
       return xmlData;
   }
};

class DataAnalyticsTool{
   string jsonData;

   public:

   DataAnalyticsTool(){}

       DataAnalyticsTool(string jsonData){
           this->jsonData=jsonData;
       }

      virtual void analyseData(){

           cout<<"Analysing data "<<jsonData<<endl;
       }
   

};

// Convert any data to json data 
class Adapter:public DataAnalyticsTool{
   // here we put any data need to be converted to dataAnayltic tool 
   XmlData*xmlData;
   public:
   Adapter(XmlData *xmlData)
   {
       this->xmlData=xmlData;
   }

   void analyseData ()override{

      cout <<"Converting Xml Data "<<xmlData->getXmlData()<<" to Json Data"<<endl;
       // Analysis

       DataAnalyticsTool::analyseData();
   }
};

class Client{

   public:
       void processData(DataAnalyticsTool*tool){
           tool->analyseData();
       }
   };
   
   int main()
   {
       XmlData*xmlData =new XmlData("Sample xml data");
   
      // Call the adapter to convert the data 
       DataAnalyticsTool*tool= new Adapter(xmlData);
   
           Client*client=new Client;
   
           client->processData(tool);
   
   }