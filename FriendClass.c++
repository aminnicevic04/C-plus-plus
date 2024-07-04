#include <iostream>
using namespace std;

class EquilateralTriangle{
private:
    float a;
    float circumferance;
    float area;
public:
    void setA(float lenght){
        a = lenght;
        circumferance = a*3;
        area = (1.73 * a * a) / 4;
    }

    friend class Homework;
};

class Homework{
public:
    void PrintResults(EquilateralTriangle et){
        cout<<"circumference =" <<et.circumferance<<endl;
        cout<<"area =" <<et.area<<endl;
};

};



int main(){
    EquilateralTriangle et;
    et.setA(3);
    Homework h;

    h.PrintResults(et);

    system("pause>nul");
}