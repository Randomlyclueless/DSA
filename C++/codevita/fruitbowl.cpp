#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

// Calculate distance between two points
double distance(const Point &a, const Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Cross product to determine orientation
long long cross(const Point &O, const Point &A, const Point &B)
{
    return (long long)(A.x - O.x) * (B.y - O.y) - (long long)(A.y - O.y) * (B.x - O.x);
}

// Convex Hull using Andrew's algorithm
vector<Point> convexHull(vector<Point> points)
{
    int n = points.size();
    if (n <= 1)
        return points;

    sort(points.begin(), points.end(), [](const Point &a, const Point &b)
         { return a.x < b.x || (a.x == b.x && a.y < b.y); });

    // Build lower hull
    vector<Point> hull;
    for (int i = 0; i < n; i++)
    {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    // Build upper hull
    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; i--)
    {
        while (hull.size() > lower_size && cross(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back(); // Remove duplicate point
    return hull;
}

// Calculate perimeter of the bowl (convex hull)
double calculateBowlPerimeter(const vector<Point> &hull)
{
    double perimeter = 0.0;
    int n = hull.size();

    for (int i = 0; i < n; i++)
    {
        perimeter += distance(hull[i], hull[(i + 1) % n]);
    }

    return perimeter;
}

int main()
{
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    // Get convex hull (this forms the bowl shape)
    vector<Point> hull = convexHull(points);

    // Calculate perimeter
    double perimeter = calculateBowlPerimeter(hull);

    // Round to nearest integer
    int result = (int)round(perimeter);

    cout << result << endl;

    return 0;
}