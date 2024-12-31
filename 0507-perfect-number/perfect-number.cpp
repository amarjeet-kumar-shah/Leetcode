class Solution {
public:
    bool checkPerfectNumber(int num) {
    /* 
        A perfect number is a positive integer that is equal to the sum of its positive divisors, 
        excluding the number itself. example : 6 => divisor of 6 are 1,2,3 and sum of 1+2+3 = 6, so 6 is a strong number 
    */  
        // finding all divisors and its sum
        int n = num;
        int sum = 0;
        for(int i = 1; i<sqrt(n); i++) {
            if(n%i == 0) sum += i;
        }
        // we started this loop from 2 because we don't want to include n itself
        for(int i = 2; i<= sqrt(n); i++) {
            if(n%i == 0) sum += (n/i);
        }

        if(sum == n) return true;
        else return false;
    }
};