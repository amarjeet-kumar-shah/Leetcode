class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        int a = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                a = 1;
                break;
            }
        }
        if (a == 0) {
            return true;
        } else {
            return false;
        }
    }
    bool isPalindrome(int n) {
        int x = n;
        int reverse = 0;
        while (n > 0) {
            int last = n % 10;
            reverse = reverse * 10;
            reverse = reverse + last;
            n /= 10;
        }
        return x == reverse;
    }
    int primePalindrome(int n) {
        if(n>=9989900) return 100030001;
        int ans;
        for (int i = n; i <= 100000000; i++) {
            if (isPrime(i) && isPalindrome(i)) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};