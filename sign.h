#ifndef SIGN_H
#define SIGN_H

enum SignType
{
    NUM,
    OPT,
    LPAR,
    RPAR
};

class Sign
{
private:
    char sign;
    SignType type;
    int priority;
public:
    Sign(char _sign, SignType _type, int _priority);
    char getSign();
    int getPriority();
    SignType getType();
};

#endif // SIGN_H
