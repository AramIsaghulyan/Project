#include "Person.h"

Person::Person (const Person & obj)
{
    this -> m_name = obj.m_name;
    this -> m_age = obj.m_age;
    this -> m_mail = obj.m_mail;
}

Person & Person::operator =(const Person & oth)
{
    this -> m_name = oth.m_name;
    this -> m_age = oth.m_age;
    this -> m_mail = oth.m_mail;
    return *this;
}

void Person::set_info ()
{
    std::cout << "Enter the name:" << std::endl;
    std::getline (std::cin,m_name);
    std::cout << "Enter the age:" << std::endl;
    std::cin >> m_age;
    std::cin.get();
    std::cout << "Enter your mail:" << std::endl;
    std::getline (std::cin,m_mail); 
}

std::string Person::get_name () const
{
    return m_name;
}

int Person::get_age () const
{
    return m_age;
}

std::string Person::get_mail () const
{
    return m_mail;
}

std::ostream & operator << (std::ostream & os,const Person & obj)
{
    os << obj.m_name << obj.m_age << obj.m_mail;
    return os;
}