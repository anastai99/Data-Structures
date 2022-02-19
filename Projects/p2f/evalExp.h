#include <iostream>
#include <string>
#include <stack>
#include <queue>

//#include "evalExp.cpp"

using std::string;
using std::stack;
using std::queue;
using std::cout;
using std::endl;
using std::min;
using std::max;

bool isValidExpression(const string &exp);

queue<string> parseExpression(const string &exp);

bool checkPrec(const string &opr1, const string &opr2);

queue<string> inFixToPostFix(queue<string> &exp);

int EvalPostFixExp(queue<string> &exp);

int EvalExp(const string &exp);