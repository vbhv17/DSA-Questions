CONVERSION OF INFIX EXPRESSION TO POSTFIX EXPRESSION

Approach: We use a stack and a string ans. Traverse the infix expression
        => If we encounter an operand, add it to the ans string
        => If we encounter a opening brace, push it into the stack
        => If we encounter a closing brace, keep popping items from the stack until we get a opening brace, then pop the opening brace too
        => If we encounter a operator, and it has lower precedence than the stack top, 
             we keep on popping elements from the stack and push them to ans until stack tops precedence does not become less than current item
             Lastly we push the current item in the stack
        =>  After we have done traversing the infix string.
               we check if there are any more items left in the stack, 
               we add them to the ans one by one        
          
//code by vbhv17
class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    int prec(char c)
    {
        if(c=='^')
          return 3;
        else if(c=='*' || c=='/')
          return 2;
        else if(c=='+' || c=='-')
          return 1;
        else 
          return -1;
    }
    
    string infixToPostfix(string s)
    {
       string postfix="";
       stack<char> st;
       for(int i=0; i<s.length(); i++)
       {
           if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
             postfix+=s[i];
           
           else if(s[i]=='(')
             st.push(s[i]);
             
           else if(s[i]==')')
           {
               while(!st.empty() and st.top()!='(')
               {
                   postfix+=st.top();
                   st.pop();
               }
               
               if(!st.empty())
                st.pop();
           }
           
           else{
                   while(!st.empty() and prec(st.top())>=prec(s[i])){
                       postfix+=st.top();
                       st.pop();
                   }
                       
                   st.push(s[i]);
                     
               }
           }
               
         while(!st.empty())
         {
             postfix+=st.top();
             st.pop();
         }
             
           return postfix;
       }
};

TC: O(N)
SC: O(N)
