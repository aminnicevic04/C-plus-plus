#include <iostream>
using namespace std;

class User {
    public:
        string FirstName;
        string LastName;
        int Age;
        string Email;   
    
    // User(){} //empty default constructor

    User(){ //default constructor
        FirstName = "nn";
        LastName = "nln";
        Age = 0;
        Email = "not set";
    };
    User(string fName, string lName, int age){ //params constructor
        FirstName = fName;
        LastName = lName;
        Age = age;
        Email = fName+"."+lName+"@mail.com";
    };

};

int main(){

    // User user1; //koriscenje prvog constructora
    User user1("Nikola", "Nikolic", 20); //Koriscenje drugog constructora

    cout<<"First name: " << user1.FirstName<<endl;
    cout<<"Last name: " << user1.LastName<<endl;
    cout<<"Age: " << user1.Age<<endl;
    cout<<"Email: " << user1.Email<<endl;

    int test;
    cout<<test;


    cin.get();
}