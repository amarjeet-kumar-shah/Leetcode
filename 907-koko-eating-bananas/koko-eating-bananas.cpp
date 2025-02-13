class Solution {
public:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        for (int i = 0; i < v.size(); i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    long long totalHours(vector<int> &v, int hourly) {
        long long totalHours = 0;
        for (int i = 0; i < v.size(); i++) {
            totalHours += (v[i] + hourly - 1) / hourly; // ceil(piles[i] / hourly) without floating point
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalH = totalHours(piles, mid);

            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;  
    }
};