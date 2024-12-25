// Solution Approach - we create a mask ..how??
// 1.Right shift elements till u get 0, the number of shifts required is the number of digits going to be AND'ed with mask
// 2.Left shift element and OR it with 1
// Example- n=5=00000......0101 ; n= 2 = 00000....010
// 1- Right shift of 5- a: 0000....010 b: 0000....01 c: 0000....0 = 0
// hence mask = 0
// since there r 3 left shists there r three right shifts
// 2. left shift,  & 1 mask- a: 0000....00|1 = 0000....001
//                           b: 0000....001|1 = 0000....011
//                           c: 0000....011|1 = 0000....111

// the c here is our mask
//  now we mask ~5 with 0000....111
class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int m = n;
        int mask = 0;
        if (n == 0)
        {
            return 1;
        }
        while (m != 0)
        {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        int ans = (~n) & mask;

        return ans;
    }
};