#include <iostream>
using namespace std;

class Instrument{
public:
    virtual void makeSound() = 0;
};

class Accordion:public Instrument{
    public:
    void makeSound(){
        cout<<"Accordion is playing...\n";
    }
};

class Piano:public Instrument{
    public:
    void makeSound(){
        cout<<"Piano is playing...\n";
    }

};

int main(){
    Instrument* i1 = new Accordion();
    // i1->makeSound();
    Instrument* i2 = new Piano();
    // i1->makeSound();

    Instrument* instruments[2] = {i1,i2};
    for(int i = 0; i<2; i++){
        instruments[i]->makeSound();
    }

    system("pause>0");
}