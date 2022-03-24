#include <iostream>
#include <fstream>
#include <vector>
#include<sstream>
#ifndef _INTERPRETATOR_
#define _INTERPRETATOR_

class Interpretator
{
public:
    Interpretator ();
    Interpretator (std::string str);
    void set_path ();
    void translate ();
private:
    struct Type
    {
        Type() {}
        Type(std::string variable,std::string val,std::string type) :
    m_variable{variable}, m_value{val}, m_type{type}{}
        std::string m_variable;
        std::string m_value;
        std::string m_type;
    };

private:
    std::string path;
    std::ifstream fin;
    std::vector<Type> m_vec;
    std::vector<std::string> m_fileVec;
    bool num_review (std::string);
    int operation_int (std::string,std::string,std::string,std::string);
    bool foo (std::string);
    void readFile (std::string);
    void error(const std::string &);
    Type make_Type(const std::string&,const std::string&,const std::string&);
    bool check (const std::string &);
    bool check_num (const std::string &);
    void check_loop (int &);
};
#endif // _INTERPRETATOR_

