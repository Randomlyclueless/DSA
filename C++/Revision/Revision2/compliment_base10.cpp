
int compliment(int n)
{

    if (n == 0)
    {
        return 1;
    }
    int ans = 0, factorial = 1;
    while (n != 0)
    {
        // Extract last bit
        int bit = n % 2;
        // Flip the bit
        bit = 1 - bit;
        // add flip bit to result
        ans += factorial * bit;
        // move to next binary place
        factorial *= 2;
        // do right shift
        n /= 2;
    }
    return ans;
}

int main()
{

    int n = 5;
    int r2 = compliment(n);
    cout << "Bitwise compliment : " << r2 << endl;
}