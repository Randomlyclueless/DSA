// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
// BRUTE FORCE APPROACH

// int main() {

// vector<int> nums = {0, 1, 0, 3, 12};
//     int lastnonzeroindex = 0;
//     for(int i=0;i<nums.size();i++){
//         if(nums[i]!=0){
//             swap(nums[i],nums[lastnonzeroindex]);
//             lastnonzeroindex++;
//         }

//     }
//     for (int i=0;i<nums.size();i++) {
//         cout << nums[i] << " ";
//     }
//     cout << endl;

// }

void moveZeroes(vector<int> &nums)
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[j], nums[i]);
            i++;
        }
    }
}
int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}