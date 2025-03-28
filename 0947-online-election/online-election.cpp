class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int max_count = 0, candidate = 0, len = persons.size();
        int count[len + 1];
        memset(count, 0, sizeof count);
        candidates = vector<pair<int, int>>(len);
        for(int i = 0; i < len; i++){
            count[persons[i]]++;
            if(count[persons[i]] >= max_count){
                max_count = count[persons[i]];
                candidate = persons[i];
            }
            candidates[i].first = times[i];
            candidates[i].second = candidate;
        }
    }
    int q(int t) {
        int lo = 0, hi = candidates.size();
        while(lo < hi){
            int m = (lo + hi) / 2;
            if(candidates[m].first <= t){
                lo = m + 1;
            }else{
                hi = m;
            }
        }
        return candidates[lo - 1].second;
    }
private:
    vector<pair<int, int>> candidates;
    };