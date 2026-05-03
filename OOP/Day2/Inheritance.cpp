#include <iostream>
using namespace std;

class Human
{
public:
    int height;
    int weight;
    int age;

public:
    int getAge()
    {
        return this->age;
    }
    int setWeight(int w)
    {
        return this->weight = w;
    }
};

class Male : public Human
{
public:
    string color;
    void sleep()
    {
        cout << "Male Sleeping" << endl;
    }
};

int main()
{
    Male object1;
    cout << object1.age << endl;
    cout << object1.color << endl;
    object1.setWeight(20);
    cout << object1.weight << endl;
    object1.sleep();
}