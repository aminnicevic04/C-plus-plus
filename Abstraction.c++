#include <iostream>
using namespace std;

class Smartphone{
    public:
    virtual void TakeASelfie() = 0;
    virtual void MakeACall() = 0;
};

class Android:public Smartphone{
    public:
        void TakeASelfie(){
            cout<<"Android selfie.\n";
        }
        void MakeACall(){
            cout<<"Android calling...\n";
        }
};

class Iphone:public Smartphone{
    public:
        void TakeASelfie(){
            cout<<"Iphone selfie.\n";
        }
        void MakeACall(){
            cout<<"Iphone calling...\n";
        }
};

int main(){
    Smartphone* s1 = new Android();
    Smartphone* s2 = new Iphone();

    s1->TakeASelfie();
    s1->MakeACall();
    
    s2->TakeASelfie();
    s2->MakeACall();

    system("pause>0");
}