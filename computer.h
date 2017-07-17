#ifndef COMPUTER_H
#define COMPUTER_H
#include <stack>
#include <queue>
#include <list>
#include "sign.h"

using std::stack;
using std::queue;
using std::list;

class Computer
{
private:
    list<Sign> record;
    stack<Sign> signStack;
    queue<Sign> postfixExp;
    double result;
    void infix2Postfix();
public:
    Computer();
    void pushStack(Sign s);
    double getResult();
    void clearStack();
    Sign popStack();
    void computeResult();
};

#endif // COMPUTER_H
