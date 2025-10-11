// Chef Bakes Cake
// Chef has baked
// N
// N cakes, each weighing
// X
// X kilograms. Now, he needs to deliver them.

// He has many vehicles, that he will use to transport the cakes. Each vehicle can carry at most
// Y
// Y kilograms of cake. It is guaranteed that
// Y
// ≥
// X
// Y≥X, so each vehicle can carry at least
// 1
// 1 cake.

// How many vehicles will Chef need to transport all the cakes?

// Input Format
// The first and only line of each test case contains
// 3
// 3 integers -
// N
// ,
// X
// N,X and
// Y
// Y.
// Output Format
// Output on a new line the minimum number of vehicles Chef will need.

// Constraints
// 1
// ≤
// N
// ≤
// 10
// 1≤N≤10
// 1
// ≤
// X
// ≤
// Y
// ≤
// 10
// 1≤X≤Y≤10
// Sample 1:
// Input
// Output
// 6 4 6
// 6
// Explanation:
// Each vehicle can only fit
// 1
// 1 cake, and thus Chef will need
// 6
// 6 vehicles for
// 6
// 6 cakes.

// Sample 2:
// Input
// Output
// 4 1 3
// 2
// Explanation:
// Chef can put
// 2
// 2 cakes in each of the
// 2
// 2 vehicles.


#include <bits/stdc++.h>
using namespace std;

// Function to calculate minimum number of vehicles needed
int minVehicles(int N, int X, int Y) {
    // Base case: Ensure each vehicle can carry at least one cake
    if (Y < X) {
        // This should not occur given problem constraints (Y >= X)
        return -1; // Indicates invalid input
    }
    
    // Number of cakes one vehicle can carry
    int cakes_per_vehicle = Y / X;
    
    // Ceiling division: ceil(N / cakes_per_vehicle)
    return (N + cakes_per_vehicle - 1) / cakes_per_vehicle;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Read single test case
    int N, X, Y;
    cin >> N >> X >> Y;
    
    // Calculate and output the result
    cout << minVehicles(N, X, Y) << "\n";
    
    return 0;
}