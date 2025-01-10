class Solution {
private:
    bool isSelfDividingNumber(int num) {
        int x = num;
        while (x) {
            int digit = x % 10;
            x /= 10;
            if (digit == 0 || num % digit)
                return false;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int num = left; num <= right; num++) {
            if (isSelfDividingNumber(num))
                ans.push_back(num);
        }
        return ans;
    }
};