#include <iostream>
#include <string>
#include <stack>
#include <queue>

#include "evalExp.h"

using std::string;
using std::stack;
using std::queue;
using std::cout;
using std::endl;
using std::min;
using std::max;



bool isValidExpression(const string &exp) {
    // Your code

    stack<char> mqueue;
    
    
    for (int i = 0; i < exp.size(); i++) {
        if(exp[i] == '('){
            mqueue.push(exp[i]);

        }

        else if(exp[i] == ')' && mqueue.size() == 0){
            return false;

        }

        else if(exp[i] == ')' && mqueue.top() == '('){
            mqueue.pop();

        }


    }

    if(mqueue.size() == 0){
        return true;
    } 
    return false;
}

queue<string> parseExpression(const string &exp) {
    // Your code
    queue<string> myqueue; //empty queue
    
    if(isValidExpression(exp)){
        
        for (int i = 0; i < exp.size(); i++){ 

            if(exp[i] == 'm' && exp[i+1] == 'a'){
                myqueue.push("max");
                
                
            }

            else if(exp[i] == 'm' && exp[i+1] == 'i'){
                myqueue.push("min");
              
                
            }

            else if(exp[i] == '+'){
                myqueue.push("+");
                
                }
            else if(exp[i] == '-'){
                myqueue.push("-");
                
                }

            else if(exp[i] == '/'){
                myqueue.push("/");
                
                }

             else if(exp[i] == '*'){
                myqueue.push("*");
                
                }
            else if(exp[i] == ')'){
                myqueue.push(")");
                
                }

            else if(exp[i] == '('){
                myqueue.push("(");
            
                }

            else if(exp[i] == ','){
                myqueue.push(",");
                continue;
            }

            string num;
            if(isdigit(exp[i])){
                while(isdigit(exp[i])){
                    char c = exp[i];
                    
                    string s;
                    s.push_back(c);
                    
                    num += s;
                    if(isdigit(exp[i+1])){
                        i++;
                    }
                    else{
                        break;
                    }
                    
                    
                }
            myqueue.push(num);
            

            }
                   
        }
     }
                 return myqueue;


            }

bool checkPrec(const string &opr1, const string &opr2) {
    /* 
        Returns true if opr1 has higher or equal precedence as opr2.
        Returns false if opr1 has loWer precedence than opr2.
    */
    if ((opr1 == "(") ||
        (opr1 == "+" && opr2 == "*") ||
        (opr1 == "+" && opr2 == "/") ||
        (opr1 == "-" && opr2 == "*") ||
        (opr1 == "-" && opr2 == "/")) {
            return false;
    } else {
        return true;
    }
}

queue<string> inFixToPostFix(queue<string> &exp){
    queue<string> postfix;
    stack<string> opstack; 

    while(!exp.empty()){

        if(isdigit(exp.front()[0])){

            postfix.push(exp.front());
            exp.pop();

        } else if (exp.front() == "("){

            opstack.push(exp.front());
            exp.pop();

        } else if (exp.front() == ")"){
            exp.pop();
   
            while(!opstack.empty()){

                if(opstack.top() != "("){

                    postfix.push(opstack.top());
                    opstack.pop();

                }
                else if(opstack.top() == "("){

                    opstack.pop();
                    break; 
                
                }
                else if((opstack.top()=="max" || (opstack.top()=="min"))){

                    postfix.push(opstack.top());
                    opstack.pop();
                    continue;

                }
                
            } 

        } else if ((exp.front() == "+") || 
                   (exp.front() == "-") ||
                   (exp.front() == "/") ||
                   (exp.front() == "*")){
                       if (opstack.empty()){
                           opstack.push(exp.front());
                           exp.pop();


                       } else{
                           while(!opstack.empty() && checkPrec(opstack.top(),exp.front())){


                           string a1 = opstack.top();
                           opstack.pop();
                           postfix.push(a1);

                           }
                        opstack.push(exp.front());
                        exp.pop(); 

                       }
                       

                         

        } else if((exp.front() == "max") || (exp.front() == "min") ){
            opstack.push(exp.front());
            exp.pop();

        }
         else if(exp.front() == ","){
            exp.pop();
            

            while (opstack.top() != "("){


                postfix.push(opstack.top());
                opstack.pop();

            }

            
        }
    } 

     if(!opstack.empty()){
        while(!opstack.empty()){
        
        string a1 = opstack.top();
        opstack.pop();
        postfix.push(a1);

        }

    }      
 return postfix;   
    
}

int EvalPostFixExp(queue<string> &exp) {
    // Your code
    stack<int> oprand;
    while(!exp.empty()){
    
        if(isdigit(exp.front()[0])  ){
           
            oprand.push(stoi(exp.front()));
            exp.pop();

        }
        
        else if((exp.front() == "+") || 
        (exp.front() == "-") ||
         (exp.front() == "/") ||
         (exp.front() == "*") ||
         (exp.front() == "max") ||
         (exp.front() == "min")){
          
             int a;
             int b;
             string sign;
             int result;
             sign  = exp.front();
             exp.pop(); 
             a = oprand.top();
             oprand.pop();
             b = oprand.top();
             oprand.pop();
             if(sign =="+"){
                 
                 result = (b + a);
                 oprand.push(result);
                 cout << "add" << oprand.top() << endl;
                 
             }
              else if(sign =="-"){
                 result = (b-a);
                 oprand.push(result);
                 cout << "minus" << oprand.top() << endl;
               
             }
             else if(sign =="*"){
                 
                 result = (b * a);
                 oprand.push(result);
                 cout << "mult" << oprand.top() << endl;    
              
             }
             else if(sign =="/"){
                 result = (b / a);
                 oprand.push(result);
                 cout << "div" << oprand.top() << endl;
                      
             } else if(sign == "max"){
                 result = max(b,a);
                 oprand.push(result);
                 cout << "max" << oprand.top() << endl;
                 
             }else if(sign == "min"){
                 result = min(b,a);
                 oprand.push(result);
                 cout << "min" << oprand.top() << endl;
                 
             }

            

        } 
    }

    return oprand.top();
}

int EvalExp(const string &exp) {
    if (!isValidExpression(exp)) {
        return -1024;
    } else {
        queue<string> parsedExp = parseExpression(exp);
        queue<string> postFixExp = inFixToPostFix(parsedExp);

        int x = EvalPostFixExp(postFixExp);
        return x;
    }
}



// int main(){
//     cout << "Actual:" <<min(1+2-3*4/5,1-2+3/4*5)<<  endl;
//     cout << "EvalExp Function:" << EvalExp("min(1+2-3*4/5,1-2+3/4*5)") <<  endl;

//     cout << "Actual:" <<max(1+2-3*4/5,1-2+3/4*5)<<  endl;
//     cout << "EvalExp Function:" << EvalExp("max(1+2-3*4/5,1-2+3/4*5)") <<  endl;

//     queue<string> myqueue;
//     myqueue = parseExpression("max(1+2-3*4/5,1-2+3/4*5)");
//     myqueue = inFixToPostFix(myqueue);
//     while(!myqueue.empty()){
//         cout << myqueue.front() << endl;
//         myqueue.pop();
//     }



    
//     return 0;
// }

