#include <iostream>
using namespace std;
int main()
{
    int num = 5;
    int a = num;
    a++;

    cout << num << endl;

    int *p = &num;
    cout << "Before : " << num << endl;
    (*p)++;
    cout << "After : " << num << endl;

    // Copying a Pointer
    int *q = p;
    cout << p << "- " << q << endl;
    cout << *p < < < "- " << *q << endl;
}