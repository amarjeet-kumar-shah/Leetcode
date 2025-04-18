class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
                // Individual areas
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);

        // Overlapping width and height
        int overlapWidth = max(0, min(ax2, bx2) - max(ax1, bx1));
        int overlapHeight = max(0, min(ay2, by2) - max(ay1, by1));

        // Overlapping area
        int overlapArea = overlapWidth * overlapHeight;

        // Total area
        return area1 + area2 - overlapArea;
    }
};