#ifndef COMPUTER_H
#define COMPUTER_H
#include <stack>
#include "sign.h"

using std::stack;

class Computer
{
private:
    stack<Sign> signStack;
    stack<Sign> expStack;
    double result;
public:
    Computer();
    void pushStack(Sign s);
    double ComputeResult();
    double getResult();
    void clearStack();
    char popStack();
};

#endif // COMPUTER_H
