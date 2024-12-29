class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        int store[200003] = {0}, n = candyType.size(), cnt = 0;
        for (int it : candyType)
        {
            if (!store[it + 100000])
            {
                ++cnt;
                ++store[it + 100000];
            }
            if (cnt > n / 2)
                return n / 2;
        }
        return cnt;
    }
};