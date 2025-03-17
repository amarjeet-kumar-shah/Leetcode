class Solution {
public:
    bool isprime(int k)
    {
        if(k==2||k==3||k==5||k==7||k==11||k==13||k==17||k==19)
        return 1;
        else
        return 0;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            int num=i;
            int cnt=0;
            while(num)
            {
                num&=(num-1);
                cnt++;
            }
            if(isprime(cnt))
            ans++;
            else
            continue;
        }
        return ans;
    }
};