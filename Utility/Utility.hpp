#include "Utility.h"
#include <regex>

bool Utility::isNumber(const std::string & str)
{
    int count = 0;

    for (int i = 0; i < str.size(); ++i)
    {
        if (!(str[i] >= 48 && str[i] <= 57 || str[i] == '.' || str[0] == '+' || str[0] == '-'))
        {
            return false;
        }
        
        if (str[i] == 46)
        {
            count++;
        }
        if (count > 1)
        {
            return false;
        }
    }
    return true ;    
}

bool Utility::isInteger (const std::string & str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (!(str[i] >= '0' && str[i] <= '9' || str[0] == '+'))
        {
            return false;
        }
    }
    return true;
}

bool Utility::isBoolean (const std::string & str)
{
    if (str == "")
    {
        return true;
    }
    return false;
}

bool Utility::isEmail (const std::string & str)
{
    std::regex re ("(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$)");
    return regex_search(str, re);
}

bool Utility::isURL (const std::string & str)
{
    std::regex re ("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
    return regex_search(str,re);
}