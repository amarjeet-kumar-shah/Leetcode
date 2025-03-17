class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1_1=rec1[0], y1_1=rec1[1], x2_1=rec1[2], y2_1=rec1[3], x1_2=rec2[0], y1_2=rec2[1], x2_2=rec2[2], y2_2=rec2[3];
        
        if(y2_2<y1_1 // Second rectangle is vertically lower than first such that they cannot overlap
        || y2_1<y1_2 // First rectangle is vertically lower than second such that they cannot overlap
        || x2_2<x1_1 // Second rectangle is horizontally to left than first such that they cannot overlap
        || x2_1<x1_2 // First rectangle is horizontally to left than second such that they cannot overlap
        || (x1_2==x2_1 && ((y1_2>=y1_1 && y1_2<=y2_1) || (y2_2>=y1_1 && y2_2<=y2_1))) // Left edge of second rectangle overlapping with Right edge of first 
        || (x1_1==x2_2 && ((y1_2>=y1_1 && y1_2<=y2_1) || (y2_2>=y1_1 && y2_2<=y2_1)))  // Left edge of first rectangle overlapping with Right edge of second 
        || (y2_2==y1_1 && ((x2_2<=x2_1 && x2_2>=x1_1) || (x1_2<=x2_1 && x1_2>=x1_1))) // Top edge of second overlapping with Bottom edge of first
        || (y1_2==y2_1 && ((x2_2<=x2_1 && x2_2>=x1_1) || (x1_2<=x2_1 && x1_2>=x1_1))) // Top edge of first overlapping with Bottom edge of second
        ) return false; 
        return true;
    }
};