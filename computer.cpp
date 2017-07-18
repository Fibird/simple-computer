#include "computer.h"
#include <QString>
#include <QDebug>
#include <string>
#include <sstream>
#include <exception>

using std::exception;

using std::string;
using std::ostringstream;

Computer::Computer()
{
    result = 0;
    hasComputed = false;
}

void Computer::pushStack(Sign s)
{
    record.push_back(s);
}

void Computer::popStack()
{
    if (!record.empty())
    {
        record.pop_back();
    }
}

void Computer::clearStack()
{
    if (!record.empty())
    {
        record.clear();
    }
}

void Computer::infix2Postfix()
{
    //QDebug debug = qDebug();
    while (!record.empty())
    {
        Sign s = record.front();
        record.pop_front();
        if (s.getType() == NUM)
        {
            postfixExp.push(s);
            //debug << s.getSign();
        }
        else if (s.getType() == OPT
                 || s.getType() == LPAR)
        {
            // insert terminator '$' of a number
            if (!postfixExp.empty() && (postfixExp.back().getSign() != '$')
                    && (postfixExp.back().getType() != OPT))
            {
                postfixExp.push(Sign('$', NUM, -1));
                //debug << '$';
            }

            while (!signStack.empty())
            {
                Sign tmp = signStack.top();
                if (tmp.getPriority() < s.getPriority()
                        || tmp.getType() == LPAR)
                {
                    break;
                }
                postfixExp.push(tmp);
                //debug << tmp.getSign();
                signStack.pop();
            }
            signStack.push(s);
        }
        else if (s.getType() == RPAR)
        {
            // insert terminator '$' of a number
            if (!postfixExp.empty()
                    && postfixExp.back().getSign() != '$')
            {
                postfixExp.push(Sign('$', NUM, -1));
                //debug << '$';
            }
            while (!signStack.empty())
            {
                Sign tmp = signStack.top();
                signStack.pop();
                if (tmp.getType() == LPAR)
                {
                    break;
                }
                postfixExp.push(tmp);
                //debug << tmp.getSign();
            }
        }
    }
    if (!postfixExp.empty()
            && (postfixExp.back().getType() == NUM)
            && (postfixExp.back().getSign() != '$'))
    {
        postfixExp.push(Sign('$', NUM, -1));
    }
    while (!signStack.empty())
    {
        Sign tmp = signStack.top();
        signStack.pop();
        postfixExp.push(tmp);
        //debug << tmp.getSign();
    }
}

void Computer::computeResult()
{
    stack<double> Stack;
    QString num = "";

    while (!postfixExp.empty())
    {
        Sign tmp = postfixExp.front();

        postfixExp.pop();
        if (tmp.getType() == NUM)
        {
            while (tmp.getSign() != '$')
            {
                num.append(tmp.getSign());
                if (!postfixExp.empty())
                {
                    tmp = postfixExp.front();
                    postfixExp.pop();
                }
                else
                {
                    // error
                    throw exception();
                }
            }

            qDebug() << "number: " << num;
            bool isok;
            double dblNum = num.toDouble(&isok);
            if (isok)
            {
                Stack.push(dblNum);
                num.clear();
            }
            else
            {
                // error
                throw exception();
            }
        }
        else if (tmp.getType() == OPT)
        {

            // pop two numbers
            double rightNum, leftNum;
            if (!Stack.empty())
            {
                rightNum = Stack.top();
                Stack.pop();
                if (!Stack.empty())
                {
                    leftNum = Stack.top();
                    Stack.pop();
                }
                else
                {
                    // error
                    throw exception();
                }
            }

            // compute according operator
            switch (tmp.getSign())
            {
            case '+':
                leftNum = leftNum + rightNum;
                break;
            case '-':
                leftNum = leftNum - rightNum;
                break;
            case '*':
                leftNum = leftNum * rightNum;
                break;
            case '/':
                leftNum = leftNum / rightNum;
                break;
            default:
                // TODO: throw error exception
                break;
            }

            // push result into stack
            Stack.push(leftNum);
        }
    }

    if (!Stack.empty())
        result = Stack.top();
}

double Computer::getResult()
{
    return result;
}

void Computer::setHasComputed(bool flag)
{
    hasComputed = flag;
}

bool Computer::getHasComputed()
{
    return hasComputed;
}
