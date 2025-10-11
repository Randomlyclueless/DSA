// rotate array to right by K steps
// Brute Force Approach


// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         // Brute Force
//         // k is num of stemps to rotate 
//         int n = nums.size();
//         // n%k gives rotationsexplain brute 
//         k = k%n;
//         // outer loop - repeat k rotations 
//         for(int r = 0;r<k;r++){
//             // step 1- save the last element 
//             int last = nums[n-1];
//             for(int i = n-1;i>0;i--){
//                 // shift right
//                 nums[i] = nums[i-1];
//             }
//             // place saved element at front
//             nums[0] = last;
//         }
//         Input: nums = [1,2,3,4,5,6,7], k=3

// Before loop: n=7, k=3

// 1st rotation:

// Save last=7

// Shift → [1,1,2,3,4,5,6]

// Put 7 at start → [7,1,2,3,4,5,6]

// 2nd rotation:

// Save last=6

// Shift → [7,7,1,2,3,4,5]

// Put 6 at start → [6,7,1,2,3,4,5]

// 3rd rotation:

// Save last=5

// Shift → [6,6,7,1,2,3,4]

// Put 5 at start → [5,6,7,1,2,3,4] ✅

// Final Answer: [5,6,7,1,2,3,4]

//     }
// };






class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> temp(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            temp[(i + k) % nums.size()] = nums[i];
        }
        nums = temp;
    }
};