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
