#ifndef COMPUTER_H
#define COMPUTER_H
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <QString>
#include "sign.h"

using std::stack;
using std::queue;
using std::list;
using std::string;

class Computer
{
private:
    list<Sign> record;
    stack<Sign> signStack;
    queue<Sign> postfixExp;
    double result;
    bool hasComputed;
public:
    Computer();
    void pushStack(Sign s);
    double getResult();
    QString getResultStr();
    void clearStack();
    void popStack();
    Sign getBack();
    bool isEmpty();
    void infix2Postfix();
    void computeResult();
    void setHasComputed(bool flag);
    bool getHasComputed();
};

#endif // COMPUTER_H
