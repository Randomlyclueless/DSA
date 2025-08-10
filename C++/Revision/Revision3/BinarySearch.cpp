#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Find first occurrence using binary search
int first_occurrence(vector<int>& arr, int n, int key) {
    int s = 0, e = n - 1, mid = s + (e - s) / 2, ans = -1;
    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        } else if (arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

// Find last occurrence using binary search
int last_occurrence(vector<int>& arr, int n, int key) {
    int s = 0, e = n - 1, mid = s + (e - s) / 2, ans = -1;
    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        } else if (arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

// Find peak index in mountain array
int Peak_Index(vector<int> arr, int n) {
    int s = 0, e = n - 1;
    while (s < e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1]) {
            s = mid + 1;
        } else {
            e = mid;
        }
    }
    return s;
}

// Find pivot in rotated sorted array
int getpivot(vector<int>& arr, int n) {
    int s = 0, e = n - 1, mid;
    while (s < e) {
        mid = s + (e - s) / 2;
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;
        }
    }
    return s;
}

// Find pivot index where left sum = right sum
int find_sum_pivot(vector<int>& nums) {
    int totalSum = 0, leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        totalSum += nums[i];
    }

    for (int i = 0; i < nums.size(); i++) {
        int rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum) return i;
        leftSum += nums[i];
    }
    return -1;
}

// Square root using binary search
long long mysqrt(int x) {
    long long s = 0, e = x, ans = -1;
    while (s <= e) {
        long long mid = s + (e - s) / 2;
        long long square = mid * mid;
        if (square == x) {
            return mid;
        } else if (square < x) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

// Main function to test all
int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};

    // First and Last Occurrence
    int key = 2;
    cout << "First Occurrence of " << key << ": " << first_occurrence(arr, arr.size(), key) << endl;
    cout << "Last Occurrence of " << key << ": " << last_occurrence(arr, arr.size(), key) << endl;

    // Peak Index in Mountain Array
    vector<int> mountain = {1, 3, 5, 7, 6, 4, 2};
    cout << "Peak Index: " << Peak_Index(mountain, mountain.size()) << endl;

    // Pivot in Rotated Sorted Array
    vector<int> rotated = {5, 6, 7, 1, 2, 3, 4};
    cout << "Pivot Index in Rotated Array: " << getpivot(rotated, rotated.size()) << endl;

    // Pivot index where left sum = right sum
    vector<int> pivotSumArr = {1, 7, 3, 6, 5, 6};
    cout << "Pivot Index (LeftSum == RightSum): " << find_sum_pivot(pivotSumArr) << endl;

    // Square Root
    int num = 37;
    cout << "Integer Square Root of " << num << ": " << mysqrt(num) << endl;

    return 0;
}
