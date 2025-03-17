class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> result;
        unordered_map<string, int> countPairedDomainsMap;
        for(int i=0;i<cpdomains.size();i++) {
            string cpdomain = cpdomains[i];
            int cnt = 0;
            for(int j=0;j<cpdomain.size();j++) {
                if(cpdomain[j]==' ') break;
                cnt = cnt*10 + (cpdomain[j]-'0');
            }
            string subdomain = "";
            for(int j=cpdomain.size()-1;j>=0;j--) {
                if(cpdomain[j]==' ') {
                    countPairedDomainsMap[subdomain] += cnt;
                    break;
                }
                else if(cpdomain[j]=='.') {
                    countPairedDomainsMap[subdomain] += cnt;
                    subdomain = cpdomain[j] + subdomain;
                }
                else subdomain = cpdomain[j] + subdomain;
            }
        }
        for(auto& it: countPairedDomainsMap) {
            result.push_back(to_string(it.second) + " " + it.first);
        }
        return result;
    }
};