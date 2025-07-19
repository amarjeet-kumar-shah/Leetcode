
class FindSumPairs {
public:
    vector<int> n1, n2; unordered_map<int, int> m;
    FindSumPairs(vector<int>& ns1, vector<int>& ns2) {
        n1 = ns1; n2 = ns2; sort(begin(n1), end(n1));
        for (int x: n2) ++m[x];
    }
    void add(int i, int v) { --m[n2[i]]; n2[i] += v; ++m[n2[i]]; }
    int count(int t) {
        int r = 0;
        for (int x: n1) if (x > t) break; else r += m[t - x];
        return r;
    }
};
