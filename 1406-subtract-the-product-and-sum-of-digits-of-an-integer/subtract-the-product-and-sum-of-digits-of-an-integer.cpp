class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum =0;
        int prod =1;
        int a;
        while(n!=0){
           a = n %10;
           n = n/10;
           prod = prod * a;
           sum = sum + a;
        }
        int ans = prod - sum;

        return ans ;
    }
};