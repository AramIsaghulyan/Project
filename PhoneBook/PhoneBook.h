#include "Person.h"
#include <fstream>
#include <iostream>

class PhoneBook
{
    public:

    void show ();
    void search ();
    void read ();
    void delete_contact ();
    void interface ();
    void insert(const Person rhs);
    
    private:
    std::vector <Person> m_vec;
};


void PhoneBook::show ()
{
    for (int i = 0; i < m_vec.size(); ++i)
    {
        std::cout << m_vec[i] << std::endl;
    }
}

void  PhoneBook::read ()
{
    std::ifstream oin;
    std::string resulte;
    Person obj;
    std::string path = "MyText.txt";
    oin.open (path);
    if (oin.is_open ())
    {
        std::cout << "OK" << std::endl;
    }
    else
    {
        std::cout << "Error";
        std::exit(1) ;
    }
    while (!oin.eof())
    {
        resulte = "";
        oin >> resulte;
        obj.set_name (resulte);
        resulte = "";
        oin >> resulte;
        obj.set_surname (resulte);
        resulte = "";
        oin >> resulte;
        obj.set_address (resulte);
        resulte = "";
        oin >> resulte;
        obj.set_number (resulte);
        m_vec.push_back (obj);
    }
    oin.close();
}

void PhoneBook::insert (const Person rhs)
{
    std::ofstream fin;
    std::string path = "MyText.txt";
    fin.open (path,std::ofstream::app);
    if (fin.is_open ())
    {
        std::cout << "OK" << std::endl;
    }
    else
    {
        std::cout << "Error";
        std::exit(1) ;
    }
    fin << rhs;
}

void PhoneBook::search ()
{
    PhoneBook obj;
    std::string str;
    std::cout << "Enter the number you are looking for:" << std::endl;
    std::getline (std::cin,str);
    obj.read();
    for (int i = 0; i < obj.m_vec.size(); ++i)
    {
        if (obj.m_vec[i].get_number() == str)
        {
            std::cout << obj.m_vec[i].get_name() << " " <<obj.m_vec[i].get_surname() << std::endl;
        }
    }
}

void PhoneBook::delete_contact ()
{
    PhoneBook obj;
    obj.read();
    std::string str;
    std::cout << "Enter the phone number you want to delete:" << std::endl;
    std::getline (std::cin,str);
    for (int i = 0; i < obj.m_vec.size(); ++i)
    {
        if (obj.m_vec[i].get_number() == str)
        {
            obj.m_vec.erase(obj.m_vec.begin() + i);
        }
    }
    std::ofstream fin;
    fin.open ("MyText.txt", std::ofstream::out | std::ofstream::trunc);
    for (int i = 0; i < obj.m_vec.size(); ++i)
    {
        fin << obj.m_vec[i];
    }
}

void PhoneBook::interface ()
{
    Person obj;
    PhoneBook obj1;
    std::cout << "What action do you want to take?" << std::endl;
    std::cout << "1.Read: (R)" << std::endl;
    std::cout << "2.Wreat: (W)" << std::endl;
    std::cout << "3.Search: (S)" << std::endl;
    std::cout << "4.Delete: (D)" << std::endl;
    char operation;
    read() ;
    std::cin >> operation;
    std::cin.get();
    switch (operation)
    {
    case 'R':
        show();
        break;
    case 'D':
        delete_contact();
        break;
    case 'S':
        search();
    case 'W':
        obj.set();
        obj1.insert(obj);
        break;
    default:
        break;
    }
}