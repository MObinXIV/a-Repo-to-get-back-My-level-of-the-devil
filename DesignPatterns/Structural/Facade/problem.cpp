#include <iostream>

using namespace std;


class Message{

    private:

    string content;

    public:

    Message(string content){
        this->content=content;
    }
};

class Connection
{

public:
void disconnect(){}
};

class AuthToken
{

};
class NotificationServer
{
    // connect ()->connection
    //authenticate(appID,key)->AuthToken
    //send(authToken,message,target)
    //conn.disconnect()

    public:
     
     Connection* connect(string ipAddress){
        return new Connection();
     }

     AuthToken*authenticate(string appID, string key){
        return new AuthToken();
     }

     void send(AuthToken* authToken, Message*message , string target){

        cout<<"Sending a message\n";
     }
};

int main()
{
    NotificationServer *server = new NotificationServer;

    Connection *connection =server->connect("ip");
    AuthToken*authToken= server->authenticate("appId","key");

        Message*message=new Message("Hello world");
    server->send(authToken,message,"target");

    connection->disconnect();
    delete server;
}