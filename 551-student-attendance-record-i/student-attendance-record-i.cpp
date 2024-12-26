class Solution
{
public:
    bool checkRecord(string s)
    {
        int cntA = 0, cntL1 = 0, cntL2 = 0, ls = s.size();
        int l = 0, r = ls - 1;
        while (l <= r)
        {
            switch (s[l])
            {
            case ('P'):
                if (cntL1 > 2)
                    return false;
                cntL1 = 0;
                break;
            case ('A'):
                if (cntL1 > 2)
                    return false;
                cntL1 = 0;
                ++cntA;
                break;
            case ('L'):
                ++cntL1;
            }
            switch (s[r])
            {
            case ('P'):
                if (cntL2 > 2)
                    return false;
                cntL2 = 0;
                break;
            case ('A'):
                if (cntL2 > 2)
                    return false;
                cntL2 = 0;
                ++cntA;
                break;
            case ('L'):
                ++cntL2;
            }
            ++l;
            --r;
        }
        if (ls % 2)
        {
            if (s[l - 1] == 'L')
                return cntA < 2 && cntL1 + cntL2 < 4;
            if (s[l - 1] == 'A')
                return cntA < 3;
            return cntA < 2;
        }
        return cntA < 2 && cntL1 + cntL2 < 3;
    }
};