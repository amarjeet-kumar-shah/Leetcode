class Solution {
public:
    int myAtoi(string s) {
        long long ans=0,c=0,b=0;
        
        for(int i=0;i<s.size();i++){
           
            if(s[i+1]==32){if(s[i]=='-')return 0;}
                   if(s[i+1]==32){if(s[i]=='+')return 0;}
            if(s[i]>=48&&s[i]<=57){
                if(s[i]==48){if(s[i+1]=='-')return 0;}
                 if(s[i]==48){if(s[i+1]=='+')return 0;}
                 
                 
                 
                  
                ans=ans*10+int(s[i])-48;

                if(s[i+1]==32){if(b==1)return ans*-1; return ans;}
                 if(ans>INT_MAX) {
                     if(b==1)return INT_MIN;
                     return INT_MAX;
                 }

            } 

            if(s[i]>=48&&s[i]<=57){
                if(s[i+1]=='-'||s[i+1]=='+'){
                    if(b==1)return ans*-1;return ans;
                }
            }
            
            if(s[i]>=97&&s[i]<=122){
                break;
            }  if(s[i]==48){if(s[i+1]==32)return 0;}
             if(s[i]=='.')return ans;
                 if(s[i]=='-')b++;
                 if(b>1)return ans*-1;
                 if((s[i]=='-'&&s[i+1]=='+')||(s[i]=='+'&&s[i+1]=='-')) return 0;
                if(s[i]=='-'||s[i]=='+'){c++;}  
                if(c>1){if(b==1)return ans*-1;return ans;}

        }       if(b==1){ans=ans*-1;} 
        
        return ans;
    }
};