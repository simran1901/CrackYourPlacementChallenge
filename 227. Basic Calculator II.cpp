#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
    int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}
 
// Function to perform arithmetic operations.
int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}
public:
    int calculate(string tokens) {
        int i;
     
        // stack to store integer values.
        stack <int> values;
     
        // stack to store operators.
        stack <char> ops;
     
        for(i = 0; i < tokens.length(); i++){
         
            // Current token is a whitespace, skip it.
            if(tokens[i] == ' ')
                continue;
         
            else if(isdigit(tokens[i])){
                int val = 0;
             
                // There may be more than one digits in number.
                while(i < tokens.length() && isdigit(tokens[i]))
                {
                    val = (val*10) + (tokens[i]-'0');
                    i++;
                }
             
                values.push(val);
                i--;
            }
        
            // Current token is an operator.
            else
            {
                while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){
                    int val2 = values.top();
                    values.pop();
                 
                    int val1 = values.top();
                    values.pop();
                 
                    char op = ops.top();
                    ops.pop();
                 
                    values.push(applyOp(val1, val2, op));
                }
             
                // Push current token to 'ops'.
                ops.push(tokens[i]);
            }
        }
     
        while(!ops.empty()){
            int val2 = values.top();
            values.pop();
                 
            int val1 = values.top();
            values.pop();
                 
            char op = ops.top();
            ops.pop();
                 
            values.push(applyOp(val1, val2, op));
        }
     
        // Top of 'values' contains result, return it.
        return values.top();
    }
};