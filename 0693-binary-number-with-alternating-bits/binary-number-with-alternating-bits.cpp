class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int k = n % 2;
        n >>= 1;
        while (n)
        {
            if (n % 2 == k)
                return false;
            k = n % 2;
            n >>= 1;
        }
        return true;
    }
};