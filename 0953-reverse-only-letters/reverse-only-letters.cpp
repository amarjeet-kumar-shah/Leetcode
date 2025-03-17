class Solution {
public:
    string reverseOnlyLetters(string s) {
        string a;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                 a.push_back(s[i]);
                 s[i]=' ';}}
        reverse(a.begin(),a.end());
        int x=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                s[i]=a[x];
                x++;}}
return s;
    }
};