class Solution {
public:
    int eval(int a,int b,string op)
    {
        if(op=="+") return a+b;
        if(op=="-") return a-b;
        if(op=="*") return a*b;
        if(op=="/") return a/b;
        return 0;
    }
    int evalRPN(vector<string>& tokens) 
    {
        stack<int>s;

        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" ||tokens[i]=="-" ||tokens[i]=="*" ||tokens[i]=="/")
            {
                int b =s.top();
                s.pop();
                int a =s.top();
                s.pop();
                s.push(eval(a,b,tokens[i]));
            }
            else
            {
                s.push(stoi(tokens[i]));
            }

            cout<<s.top()<<endl;
        }
        return s.top();
    }
};