#include <iostream>
using namespace std;
//Question 1
class car
{
private:
    int speed;

public:
    void setspeed(int s)
    {
        speed = s;
    }
    int getspeed()
    {
        return speed;
    }
};
int main()
{
    car c;
    c.setspeed(42);
    cout << "Speed of car is: " << c.getspeed() << endl;
}


// Question 2 