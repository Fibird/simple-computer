#include "sign.h"

Sign::Sign(char _sign, SignType _type, int _priority)
    : sign(_sign),
      type(_type),
      priority(_priority)
{

}

char Sign::getSign()
{
    return sign;
}

int Sign::getPriority()
{
    return priority;
}

SignType Sign::getType()
{
    return type;
}

void Sign::setSign(char s)
{
    sign = s;
}

void Sign::setType(SignType t)
{
    type = t;
}
