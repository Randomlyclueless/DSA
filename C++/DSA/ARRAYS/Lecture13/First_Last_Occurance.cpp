
int firstocc(vector<int> &arr, int n, int key)
{
    int s = 0, end = n - 1;
    int mid = s + (end - s) / 2;
    int ans = -1;
    while (s <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1; // Search in the left half
        }
        else if (key > arr[mid])
        {
            s = mid + 1; // Search in the right half
        }
        else
        {
            end = mid - 1; // Search in the left half
        }
        mid = s + (end - s) / 2;
    }
    return ans;
}

int lastocc(vector<int> &arr, int n, int key)
{
    int s = 0, end = n - 1;
    int mid = s + (end - s) / 2;
    int ans = -1;
    while (s <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1; // Search in the left half
        }
        else if (key > arr[mid])
        {
            s = mid + 1; // Search in the right half
        }
        else
        {
            end = mid - 1; // Search in the left half
        }
        mid = s + (end - s) / 2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    pair<int, int> p;
    p.first = firstocc(arr, n, k);
    p.second = lastocc(arr, n, k);
    return p;
}
