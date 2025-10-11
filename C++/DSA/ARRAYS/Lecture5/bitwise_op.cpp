// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main()
{
    int a = 4;
    int b = 6;
    cout << "a and b " << (a & b) << endl;
    cout << "a | b " << (a | b) << endl;
    cout << "~a " << ~a << endl;
    cout << "a ^ b:" << (a ^ b) << endl;

    cout << "17>>1:; " << (17 >> 1) << endl;
    cout << "17>>2 :" << (17 >> 2) << endl;
    cout << "19<<1 :" << (19 << 1) << endl;
    cout << "19<<2 :" << (19 << 2) << endl;

    int i = 7;
    cout << "pre increment : " << (++i);
    cout << "post increment : " << (i++);
    cout << "pre decrement : " << (i--);
    cout << "Post decremen : " << (--i);
}