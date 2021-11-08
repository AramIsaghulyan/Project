#include <iostream>

struct Person
{
    std::string m_name;
    int m_age;
    std::string m_mail;
};
void set_name (Person *,std::string);
void set_age (Person *,int);
void set_mail (Person *,std::string);
std::string get_name (Person*);
int get_age (Person*);
std::string get_mail (Person*);
void PersDefCtor (Person *);
void PersParCtor (Person *,std::string,int,std::string);
void PersCopyCtor (Person *,Person*);
Person& Operator (Person *,Person*);

int main ()
{
    std::cout << "Enter the name:" << std::endl;
    std::string name;
    std::getline (std::cin,name);
    std::cout << "Enter the age:" << std::endl;
    int age;
    std::cin >> age;
    std::cin.get();
    std::cout << "Enter the mail:" << std::endl;
    std::string mail;
    std::getline (std::cin,mail);
    Person obj;
    Person ob;
    set_name(&obj,name);
    set_age(&obj,age);
    set_mail(&obj,mail);
    std::cout << get_name(&obj) << std::endl;
    std::cout <<get_age(&obj) << std::endl;
    std::cout << get_mail(&obj) << std::endl;
    
}

void set_name (Person* obj,std::string name)
{
    obj->m_name = name;
}

void set_age (Person* obj,int age)
{
    obj->m_age = age;
}

void set_mail (Person* obj,std::string mail)
{
    obj->m_mail = mail;
}

std::string get_name (Person* obj)
{
    return obj->m_name;
}

int get_age (Person* obj)
{
    return obj->m_age;
}

std::string get_mail (Person* obj)
{
    return obj->m_mail;
}

void PersDefCtor (Person *obj)
{
    obj->m_name = "";
    obj->m_age = 0;
    obj->m_mail = "";
}

void PersParCtor (Person *obj,std::string name,int age,std::string mail)
{
    obj->m_name = name;
    obj->m_age = age;
    obj->m_mail = mail;
}

void PersCopyCtor (Person* that,Person* obj)
{
    that->m_name = obj->m_name;
    that->m_age = obj->m_age;
    that->m_mail = obj->m_mail;
}

Person& Operator (Person* ob,Person* obj)
{
    ob->m_name = obj->m_name;
    ob->m_age = obj->m_age;
    ob->m_mail = obj->m_mail;
    return *ob;
}