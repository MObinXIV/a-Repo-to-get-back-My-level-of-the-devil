// Simple interface to complex system

/*
Interface 'll handle all the previous main work
to make it easy for the user to work 
whenever we change it 'll be in the interface , other places aren't gonna be broken
*/
#include<iostream>

using namespace std;
class Message
{

private:
    string content;

public:
    Message(string content)
    {
        this->content = content;
    }
};

class Connection
{

public:
    void disconnect() {}
};

class AuthToken
{
};
class NotificationServer
{
    // connect ()->connection
    // authenticate(appID,key)->AuthToken
    // send(authToken,message,target)
    // conn.disconnect()

public:
    Connection *connect(string ipAddress)
    {
        return new Connection();
    }

    AuthToken *authenticate(string appID, string key)
    {
        return new AuthToken();
    }

    void send(AuthToken *authToken, Message *message, string target)
    {

        cout << "Sending a message\n";
    }
};

class NotificationService
{

    public:

    void send (string message , string target){
        NotificationServer *server = new NotificationServer;

        Connection *connection = server->connect("ip");
        AuthToken *authToken = server->authenticate("appId", "key");

        
        server->send(authToken,new Message(message), target);

        connection->disconnect();
    }
};
int main()
{
    NotificationService*sever=new NotificationService;
    sever->send("hello wrld","target");
}