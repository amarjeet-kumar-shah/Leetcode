class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size(), cir = 0, sqr = 0;
        for(int i = 0; i < n; ++i){
            if(students[i]) ++cir;
            else ++sqr;
        }
        for(int i = 0; i < n; ++i){
            if(cir && sandwiches[i]) --cir;
            else if(sqr && sandwiches[i] == 0) --sqr;
            else return n - i;
        }
        return 0;
    }
};