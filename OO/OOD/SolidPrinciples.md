# Introduction to Solid Principles

## SRP (Single responsibility principle)

software element (classes , modules ,function ..etc) has one, and only one, reason to change.

For example the function to sum numbers don't suppose to draw circle 
this violate even the logical thinking.

## OCP (Open closed principle)

Software elements should be open for extension closed for modifications. (interface usage).

For example changing of payment methods , if we want to change the method it's bad practise to change the code of the  method inside the function itself , but the best practise is to use general interface, any method can extend it 

`// Violating the principle 
// here every time we need to violate the work by adding more if else 
class PaymentProcessor {
public:
    void processPayment(string type) {
        if (type == "CreditCard") {
            cout << "Processing Credit Card payment" << endl;
        } else if (type == "PayPal") {
            cout << "Processing PayPal payment" << endl;
        } else {
            throw invalid_argument("Unsupported payment method");
        }
    }
};
// Apply it 
// Abstract base class (interface)
class PaymentMethod {
    public:
        virtual void pay() = 0; // Pure virtual function
        virtual ~PaymentMethod() {} // Virtual destructor
    }; 
    // Concrete implementations
    class CreditCardPayment : public PaymentMethod {
    public:
        void pay() override {
            cout << "Processing Credit Card payment" << endl;
        }
    };
    class PayPalPayment : public PaymentMethod {
    public:
        void pay() override {
            cout<< "Processing PayPal payment" << endl;
        }
    };
    // PaymentProcessor does NOT need modification when adding new payment methods
    class PaymentProcessor {
    public:
        void processPayment(PaymentMethod* paymentMethod) {
            paymentMethod->pay();
        }
    };`

### LSP (Liskov's substitution principle)

Parent Class Can be used to work instead children , on other way don't violate the Abstraction & all the child class the parent can call them.

### ISP (Interface segregation principle)

Code shouldn't be forced to depend methods that doesn't use.
If we use car for example violation is to have functions to work with electerical & gasoline , the ones works with electric don't need gasoline , the best practise is to   seperate the 2 classes.

### DIP (Dependency inversion principle)

High level modules shouldn't depend pn low level modules.going from high level to low level should only be done via interfaces
Abstraction & details shouldn't depend on each other.

`class IMessage{
   public:
   virtual void sendMessage()=0;
};
class SmtpMessage: public IMessage{
   virtual void sendMessage(){
      cout<<"Hello";
   }
};
class PushMessage: public IMessage{
   public:
   virtual void sendMessage(){
      cout<<"Hello";
   }
};
class MessageSender{
   public:
   void send(IMessage*message){
      message->sendMessage();
   }
};`