class Solution {
public:
int totalFruit(vector<int>& fruits) {
    unordered_set<int> visited = { fruits[0] };
    int i0 = 0, i1=0;
    int i = 0;
    while (visited.size() == 1 && ++i < fruits.size()) 
        visited.insert(fruits[i]);
    if (i == fruits.size()) return i;
    i1 = i;
    int res = 0;
    for (;i < fruits.size();i++) {
        if (visited.count(fruits[i]) == 0) {
            res = max(i - i0, res);
            i0 = i1;
            i1 = i;
            visited = { fruits[i], fruits[i - 1] };
        }
        else if (fruits[i] != fruits[i - 1]) {
            i1 = i;
        }
    }
    res = max(i - i0, res);
    return res;
}

};