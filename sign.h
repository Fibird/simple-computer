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
    void setSign(char s);
    int getPriority();
    SignType getType();
    void setType(SignType t);
};

#endif // SIGN_H
