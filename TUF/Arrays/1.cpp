// Given an array, we have to find the largest element in the array.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largest = nums[0];
        for(int i = 0; i < nums.size() - 1; i++){
            
            if(nums[i] > largest){
                largest = nums[i];
            }
        }
        return largest;
    }
};

int main() {
    vector<int> nums = {3, 5, 2, 9, 1};

    Solution obj;
    int result = obj.largestElement(nums);

    cout << "Largest element is: " << result << endl;

    return 0;
}