class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum =0;
        int digit;
        while(n!=0){
            digit = n%10;
           sum = sum + digit;
           prod = prod *digit;
            n = n/10;

        }
        return prod - sum;
    }
};