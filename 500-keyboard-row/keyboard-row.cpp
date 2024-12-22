class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> ans;
        int a[27];//     Create the hash map
        a[16] = a[22] = a[4] = a[17] = a[19] = a[24] = a[20] = a[8] = a[14] = a[15] = 1;
        a[0] = a[18] = a[3] = a[5] = a[6] = a[7] = a[9] = a[10] = a[11] = 2;
        a[25] = a[23] = a[2] = a[21] = a[1] = a[13] = a[12] = 3;
        for (string it : words)
        {
            int i = 0;
            bool flag1 = false, flag2 = false, flag3 = false;
            while (it[i] != '\0')
            {
                switch (a[tolower(it[i]) - 'a'])
                {
                case (1):
                    flag1 = true;
                    break;
                case (2):
                    flag2 = true;
                    break;
                case (3):
                    flag3 = true;
                }
                if (flag1 + flag2 + flag3 > 1)
                    break;
                ++i;
            }
            if (it[i]=='\0')
                ans.push_back(it);
        }
        return ans;
    }
};