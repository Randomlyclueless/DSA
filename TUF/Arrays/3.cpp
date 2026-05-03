// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        for(int i = 0;i<n;i++){
            
            if(arr[i]>largest){
                secondLargest = largest;
                largest = arr[i];
            }else if(largest > arr[i] && arr[i] > secondLargest){
                secondLargest = arr[i];
            }
        }
        if(secondLargest == INT_MIN) return -1;

        return secondLargest;
    }
};