#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
    private: int max_speed;
    protected: int numTyres;        
    public: string color;
              Vehicle()
               {
                   cout<<"\n Vehicle default constructor";
               }
               Vehicle(int a)
               {
                   cout<<"\n Vehicle's parametrized constructor";
                   max_speed=a;
               }
               ~Vehicle()
               {
                   cout<<"\n Vehicle default destructor";
               };
               
};

class Car: public Vehicle
{
    public: int numGears;
            Car():Vehicle(7)
            {
                cout<<"\n Car default constructor";
            }
            ~Car()
            {
                cout<<"\n Car default destructor";
            }
};

int main()
{
    Vehicle v;

    Car c;
}