bool isPossible(vector<int> &arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;

        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m)
                return false;
            pageSum = arr[i];
        }
    }
    return true;
}
 
int allocateBooks(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1; // Not enough books for each student

    int start = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int end = sum;
    int ans = -1; 

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
bool canPlaceCows(vector<int> &stalls, int cows, int minDist)
{
    int count = 1; // place first cow at first stall
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPosition >= minDist)
        {
            count++;
            lastPosition = stalls[i];
        }
        if (count >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, cows, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    // Test for Book Allocation
    vector<int> books = {10, 20, 30, 40};
    int students = 2;
    cout << "Minimum pages (Book Allocation): " << allocateBooks(books, books.size(), students) << endl;

    // Test for Aggressive Cows
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << "Largest minimum distance (Aggressive Cows): " << aggressiveCows(stalls, cows) << endl;

    return 0;
}
