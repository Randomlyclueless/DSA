#include <iostream>
using namespace std;

int reverse(int n){
    int digit;
    
    int sum = 0;
    while(x!=0){
        int digit = n%10;
        if((ans>INT_MAX/10)|| (ans<INT_MIN/10)){
            return 0;
        }
        int sum = (sum *10)+digit;
        n = n/10;
    }
    return sum;
}