
#ifndef _PHONEBOOK_
#define _PHONEBOOK_
#include <iostream>
#include <vector>

class Person
{
    public:

    void set ();
    void set_name (std::string);
    void set_surname (std::string);
    void set_address (std::string);
    void set_number (std::string);
    std::string get_number ();
    std::string get_name ();
    std::string get_surname ();
    std::string get_address ();
    friend std::ostream & operator << (std::ostream & os, const Person & t);
    friend std::istream & operator >> (std::istream & is, Person & m);  
    
    private:

    std::string m_Name;
    std::string m_Surname;
    std::string m_Address;
    std::string m_Number;

};

void Person::set()
{
    std::cout << "Enter the name:" << std::endl;
    std::cin >> m_Name;
    std::cout << "Enter the surname:" << std::endl;
    std::cin >> m_Surname;
    std::cout << "Enter the address:" << std::endl;
    std::cin >> m_Address;
    std::cout << "Enter the number:" << std::endl;
    std::cin >> m_Number;
}

void Person::set_name (std::string name)
{
    m_Name = name;
}

void Person::set_surname (std::string surname)
{
    m_Surname = surname;
}

void Person::set_address (std::string address)
{
    m_Address = address;
}

void Person::set_number (std::string number)
{
    m_Number = number;
}

std::string Person::get_number  () 
{
    return m_Number;
}

std::string Person::get_name () 
{
    return m_Name;
}

std::string Person::get_surname  () 
{
    return m_Surname;
}

std::string Person::get_address  () 
{
    return m_Address;
}

std::ostream & operator << (std::ostream & os, const Person & t)
{
    os <<  "\n" << t.m_Name << "\n" << t.m_Surname << "\n" << t.m_Address << "\n" << t.m_Number;
    return os;
}

std::istream & operator >> (std::istream & is, Person & m)
{
    is >> m.m_Name >> m.m_Surname >> m.m_Address >> m.m_Number;
    return is; 
}

#endif // _PHONEBOOK_