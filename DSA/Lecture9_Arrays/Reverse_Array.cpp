#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int arr[n];

    cout << "Enter 5 array elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Reversed array: ";
    for(int i = n - 1; i >= 0; i--){
        cout << arr[i] << " ";
    }

    return 0;
}
