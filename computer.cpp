#include "computer.h"
#include <QString>
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

Computer::Computer()
{

}

void Computer::pushStack(Sign s)
{
    record.push_back(s);
}

Sign Computer::popStack()
{
    Sign tmp = record.back();
    record.pop_back();
    return tmp;
}

void Computer::clearStack()
{
    record.clear();
}

void Computer::infix2Postfix()
{
    while (!record.empty())
    {
        Sign s = record.front();
        record.pop_front();
        if (s.getType() == NUM)
        {
            postfixExp.push(s);
        }
        else if (s.getType() == OPT
                 || s.getType() == LPAR)
        {
            // insert terminator '$' of a number
            postfixExp.push(Sign('$', NUM, -1));
            while (!signStack.empty())
            {
                Sign tmp = signStack.top();
                if (tmp.getPriority() < s.getPriority()
                        || s.getType() == LPAR)
                {
                    break;
                }
                postfixExp.push(tmp);
                signStack.pop();
            }
            signStack.push(s);
        }
        else if (s.getType() == RPAR)
        {
            // insert terminator '$' of a number
            postfixExp.push(Sign('$', NUM, -1));
            while (!signStack.empty())
            {
                Sign tmp = signStack.top();
                signStack.pop();
                if (tmp.getType() == LPAR)
                {
                    break;
                }
            }
        }
    }
    while (!signStack.empty())
    {
        Sign tmp = signStack.top();
        signStack.pop();
        postfixExp.push(tmp);
    }
}

void Computer::computeResult()
{
    stack<Sign> Stack;
    QString num;
    while (!postfixExp.empty())
    {
        Sign tmp = postfixExp.front();

        postfixExp.pop();
        if (tmp.getType() == NUM)
        {
            Stack.push(tmp);
        }
        else if (tmp.getType() == OPT)
        {
            // pop two numbers
            while (!Stack.empty())
            {
                Sign tmp = Stack.top();
                Stack.pop();
                if (tmp.getSign() == '$')
                    break;
                num.insert(0, tmp.getSign());
            }
            double rightNum = num.toDouble();
            num.clear();
            while (!Stack.empty())
            {
                Sign tmp = Stack.top();
                Stack.pop();
                if (tmp.getSign() == '$')
                    break;
                num.insert(0, tmp.getSign());
            }
            double leftNum = num.toDouble();
            num.clear();
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
            ostringstream strs;
            strs << leftNum;
            string rst = strs.str();
            for (int i = 0; i < rst.length(); i++)
            {
                Stack.push(Sign(rst[i], NUM, -1));
            }
            Stack.push(Sign('$', NUM, -1));
        }
    }

    while (!Stack.empty())
    {
        Sign tmp = Stack.top();
        Stack.pop();
        if (tmp.getSign() == '$')
            break;
        num.insert(0, tmp.getSign());
    }
    result = num.toDouble();
}

double Computer::getResult()
{
    return result;
}
