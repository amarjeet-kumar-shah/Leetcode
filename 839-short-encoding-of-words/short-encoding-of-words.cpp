class trieNode{    
    public:
        unordered_map<char,trieNode*>m;  
        bool isend;
};//Our trie
class Solution {
public:
    trieNode *root;
    int c=0;
    static bool comp(string a,string b){//comparator function to sort our vector of string in a descending order        
        return a.length()>b.length();
    }
    
     trieNode *getNode(){
        trieNode *tmp=new trieNode();
        tmp->isend=false;
        return tmp;
    }
    void insert(string word) {
        if(root==nullptr)
            root=getNode();
        trieNode *tmp=root;
        int m=0;//Using this as a flag to indicate whether a string is being added to our trie or not
        for(int i=word.length()-1;i>=0;i--){//inserting the characters in a reverse order into our trie
            if(tmp->m.find(word[i])==tmp->m.end()){          
                tmp->m[word[i]]=getNode();
                m=1;
            }
            tmp=tmp->m[word[i]];
        }
        if(m!=0){//ONLY IF there is a new word we mark it as an end in the trie and update our counter as the word's length          
            tmp->isend=true;
            c+=word.length()+1;
        }
    }    
    
    int minimumLengthEncoding(vector<string>& words) {
       sort(words.begin(),words.end(),comp);
        for(auto i :words)
            insert(i);        
       
        // cout<<c<<" "<<k;
        return c;
    }
};