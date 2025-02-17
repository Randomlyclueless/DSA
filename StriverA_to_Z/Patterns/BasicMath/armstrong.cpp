bool checkArmstrong(int n)
{

    // Write your code here

    int temp = n;

    int sum = 0;

    int count = (int)(log10(n) + 1);

    while (n > 0)
    {

        int digit = n % 10;

        sum = sum + pow(digit, count);

        n = n / 10;
    }

    if (temp == sum)
    {

        return true;
    }

    else
    {

        return false;
    }
}