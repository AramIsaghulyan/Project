#ifndef _PERSON_
#define _PERSON_
#include <iostream>
#include <string>
class Person
{
    
    public:
    Person() : m_name{""}, m_age{0}, m_mail{""} {}
    Person(std::string name,int age,std::string mail) : 
        m_name{name},m_age{age}, m_mail{mail} {}
    Person (const Person & obj);
    Person & operator = (const Person & oth);
    void set_info ();
    std::string get_name () const;
    int get_age () const;
    std::string get_mail () const;
    friend std::ostream & operator << (std::ostream & os,const Person & obj);

    private:
    std::string m_name;
    int m_age;
    std::string m_mail;
    
};
#endif // _PERSON_