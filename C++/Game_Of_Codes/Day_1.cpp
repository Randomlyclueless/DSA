// PS:-
// Problem: The Upgraded Sorting Hat

// The Sorting Hat at Hogwarts School of Witchcraft and Wizardry has been magically upgraded.
// Instead of reading minds, it now senses a numerical aura for each student, which determines their house assignment.

// Houses and Magical Primes

// There are 4 houses, each linked to a unique prime number:

// House	Trait	Magical Prime
// Gryffindor	Bravery	2
// Hufflepuff	Loyalty	3
// Ravenclaw	Wisdom	5
// Slytherin	Ambition	7
// Sorting Rules

// For each student’s aura value:

// Check divisibility by the house primes in the fixed order:

// Gryffindor (2) → Hufflepuff (3) → Ravenclaw (5) → Slytherin (7)

// If the aura is divisible by one or more primes, the first matching prime in this order decides the house.

// If the aura is not divisible by any of these primes:

// Assign a house using a fallback rotation through the same order.

// Important: This rotation applies only to unmatched students — each unmatched student gets the next house in the cycle.

// Input Format
// n
// aura1 aura2 ... auran

// n = number of students

// aurai = aura value of the i-th student

// Output Format

// For each student, print:

// Student with aura X goes to House Y

// Where X is the aura value and Y is the assigned house.

// Constraints
// 1 ≤ n ≤ 10^5
// 1 ≤ aurai ≤ 10^9
// Sample Testcase 1

// Input:

// 6
// 14 15 13 10 11 21

// Output:

// Student with aura 14 goes to House Gryffindor
// Student with aura 15 goes to House Hufflepuff
// Student with aura 13 goes to House Gryffindor
// Student with aura 10 goes to House Gryffindor
// Student with aura 11 goes to House Hufflepuff
// Student with aura 21 goes to House Hufflepuff

// Sample Testcase 2

// Input:

// 4
// 11 13 17 19

// Output:

// Student with aura 11 goes to House Gryffindor
// Student with aura 13 goes to House Hufflepuff
// Student with aura 17 goes to House Ravenclaw
// Student with aura 19 goes to House Slytherin
#include <iostream>
#include <vector>
using namespace std;

string assignHouse(long long aura, int &fallbackCount)
{
    string houses[] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};
    int primes[] = {2, 3, 5, 7};

    // Check divisibility in order
    for (int i = 0; i < 4; i++)
    {
        if (aura % primes[i] == 0)
        {
            return houses[i];
        }
    }

    // Fallback for unmatched students
    string house = houses[fallbackCount % 4];
    fallbackCount++;
    return house;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> auraValues(n);

    for (int i = 0; i < n; i++)
    {
        cin >> auraValues[i];
    }

    int fallbackCount = 0; // Counts only unmatched students

    for (int i = 0; i < n; i++)
    {
        string house = assignHouse(auraValues[i], fallbackCount);
        cout << "Student with aura " << auraValues[i]
             << " goes to House " << house << "\n";
    }

    return 0;
}
