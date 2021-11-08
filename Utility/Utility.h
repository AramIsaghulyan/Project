#include <iostream>
#include <string>
class Utility
{
public:
    static bool isNumber(const std::string & str);
    static bool isInteger(const std::string & str);
    static bool isFloat(const std::string & str);
    static bool isBoolean(const std::string & str);
    static bool isEmail(const std::string & str);
    static bool isURL(const std::string & str);
};