#include <iostream>
#include <string>
#include <algorithm>
#include "Interpretator.h"

Interpretator::Interpretator (std::string str)
{
    path = str ;
        fin.open(path);
        if (!fin.is_open())
        {
            set_path ();
        } else {
            translate ();
        }
}

void Interpretator::set_path ()
{
    std::string path = "MyText.txt";
    fin.open(path);
}

void Interpretator::translate ()
{
    readFile (path);
    for (int i = 0; i < m_fileVec.size(); ++i)
    {
        std::stringstream line(m_fileVec[i]);
        std::string word;
        line >> word;
        if (word == "tiv")
        {
            std::string type("tiv");
            line >> word;
            num_review(word);
            bool checked = check(word);
            if(!checked)
            {
                error (std::string ("The variable cannot be a started white '") + word[0] + "'" );
            }
            if (word == "tiv" && "string")
            {
                error (std::string ("The variable cannot be a type name '") + word + "'");
            }
            for(auto it = m_vec.begin(); it != m_vec.end();++it)
            {
                if(it->m_variable == word)
                { 
                    error(std::string("Redifinition of '" + word + "'"));
                }
            }
            std::string variable(word);
            line >> word;
            if (word == "=")
            {
                line >> word;
                std::string value(word);
                m_vec.push_back(make_Type(variable,value,type));
            }
            else
            {
               m_vec.push_back(make_Type(variable,std::string(),type));
            }
            std::string valueforsum(word); 
            line >> word;
            bool num = check_num(word);
            if (word == "+")
            {
                line >> word;
                bool num = check_num(word);
                if (num)
                {
                    int myInt = std::stoi (word);
                    auto it = m_vec.begin();
                    for(; it != m_vec.end(); ++it) 
                    {
                        if( it->m_variable == valueforsum ) 
                        {
                            int sum = stoi(it->m_value) + myInt;
                            m_vec.back().m_value =  std::to_string(sum);
                            break;
                        }
                    }
                }
            }
            
            if(check(word))
            {
                auto it = m_vec.begin();
                for(; it != m_vec.end(); ++it) 
                {
                    if( it->m_variable == word ) 
                    {
                        m_vec.back().m_value = it->m_value;
                        break;
                    }
                }
                if (it == m_vec.end())
                {
                    error(std::string("Not allowed symbol '") + word + "'");
                }
            }
        }
        if (word == "string")
        {
            std::string type("string");
            line >> word;
            num_review(word);
            bool checked = check(word);
            if(!checked)
            {
                error (std::string ("The variable cannot be a started white '") + word[0] + "'");
            }
            if (word == "tiv" && "string")
            {
                error (std::string ("The variable cannot be a type name '") + word + "'");
            }
            for(auto it = m_vec.begin(); it != m_vec.end();++it)
            {
                if(it->m_variable == word)
                {
                    error(std::string("Redifinition of '" + word + "'"));
                }
            }
            std::string variable(word);
            line >> word;
            if (word == "=")
            {
                line >> word;
                if (word == "\"")
                {
                    std::getline (line,word,'"');
                }
                std::string value(word.begin()+1, word.end()-1);
                m_vec.push_back(make_Type(variable,value,type));
            }
            else
            {
               m_vec.push_back(make_Type(variable,std::string(),type));
            }
            
            if(check(word))
            {
                auto it = m_vec.begin();
                for(; it != m_vec.end(); ++it) 
                {
                    if( it->m_variable == word ) 
                    {
                        m_vec.back().m_value = it->m_value;
                        break;
                    }
                }
                if (it == m_vec.end())
                {
                    error(std::string("Not allowed symbol '") + word + "'");
                }
            }            
        }
        if (word == "print")
        {
            std::string type("print");
            line >> word;
            if (word == "(")
            {
                line >> word;

                if(word[0] != '"')
                {
                    for (int i = 0; i < m_vec.size(); ++i)
                    {
                        if (word == m_vec[i].m_variable)
                        {
                            std::string value (m_vec[i].m_value);
                            std::cout << m_vec[i].m_value;
                        }
                    }
                }
                if (word[0] == '"')
                {
                   std::string value(word.begin() + 1, word.end() - 1);
                   std::cout << value;
                }
                line >> word;
                line >> word;
                if (word[0] == '&')
                {
                    std::cout << std::endl;
                }
            }
        }
        if (word == "loop")
        {
            line >> word;
            if (word != "(" )
            {
                error(std::string ("Expected '(' after 'loop' "));
            }
            line >> word;
            int val1;
            int val2;
            std::string str1;
            std::string str2;
            for(auto it = m_vec.begin(); it != m_vec.end();++it)
            {
                if(it->m_variable == word)
                {
                    val1 = stoi(it->m_value);
                    str1 = word;
                    break;
                }
            }
            line >> word;
            if (word != "<" && word != ">")
            {
                error(std::string ("Use of undeclared operator '") + word + "'");
            }
            std::string op(word);
            line >> word;
            for(auto it = m_vec.begin(); it != m_vec.end();++it)
            {
                if(it->m_variable == word)
                {
                    val2 = std::stoi(it->m_value); 
                    str2 = word;
                    break;       
                }
            }
            line >> word;
            if (word != ")")
            {
                error(std::string ("Expected ')' et the and of 'loop' "));
            }
            ++i;
            if (m_fileVec[i] != "[")
            {
                error (std::string ("Expected '['"));
            }
            ++i;
            if(op == "<")
            {
                while(val1 < val2)
                {
                    int in = i;
                    check_loop(in);
                    for(auto it = m_vec.begin(); it != m_vec.end();++it)
                    {
                        if(it->m_variable == str1)
                        {
                           val1 = std::stoi(it->m_value);  
                           break;      
                        }
                    }
                }
            }
            else
            {
                while(val1 > val2)
                {
                    int in = i;
                    check_loop(in);
                    for(auto it = m_vec.begin(); it != m_vec.end();++it)
                    {
                        if(it->m_variable == str2)
                        {
                           val2 = std::stoi(it->m_value);  
                           break;      
                        }
                    }
                }
            }
        }
        // else
        // {

        // }
    }
    // for (int i = 0; i < m_fileVec.size(); ++i)
    // {
    //     std::cout << " " << m_vec[i].m_variable << " " << m_vec[i].m_value << "  ";
    // }
}

bool Interpretator::num_review (std::string str)
{
    if (str[0] >= '0' && str[0] <= '9')
    {
        std::cout << "ERROR:The name of your input variable starts with a number։" << std::endl;
        return false;
        std::exit(0);
    }
    else
    return true;
}

void Interpretator::readFile (std::string nameFile)
{
    std::string line;
    std::fstream file(nameFile, std::fstream::in);
    set_path();
    if (!file.is_open())
    {
        std::cout << "Error: The file could not be opened։" << std::endl;
    }
    else
    {
        while (!file.eof())
        {
            std::getline(file,line) ;
            m_fileVec.push_back(line);
        }
    }
    file.close();
}

void Interpretator::error(const std::string &massage)
{
    std::cout << "ERROR: /* " << massage << "*/";
    exit(1);
}

Interpretator::Type Interpretator::make_Type(const std::string& variable,const std::string& value,const std::string& type)
{
    return Type(variable,value,type);
}

bool Interpretator::check (const std::string & word)
{
    if (word[0] <= 64 || word[0] == 91 || word[0] == 92 || word[0] == 93 || word[0] == 94 || word[0] == 96 || word[0] >= 123)
      return false;
    
    return true;
}

bool Interpretator::check_num (const std::string & word)
{
    for (int i = 0; i < word.size(); ++i)
    {
        if (word[i] < '0' || word[i] > '9')
        {
            return false;
        }
    }
    return true;
}

void Interpretator::check_loop (int & i)
{
    std::stringstream line(m_fileVec[i]);
    std::string word;
    line >> word;
     if (word == "print")
        {
            std::string type("print");
            line >> word;
            if (word == "(")
            {
                line >> word;

                if(word[0] != '"')
                {
                    for (int i = 0; i < m_vec.size(); ++i)
                    {
                        if (word == m_vec[i].m_variable)
                        {
                            std::string value (m_vec[i].m_value);
                            std::cout << m_vec[i].m_value;
                        }
                    }
                }
                if (word == "\"")
                {
                   std::getline(line,word,'"');
                   std::string value(word.begin(), word.end());
                   std::cout << value;
                }
                line >> word;
                line >> word;
                if (word == "&")
                {
                    std::cout << std::endl;
                }
            }
        }
        else 
        {
            int val1;
            auto it = m_vec.begin();
            for ( ; it != m_vec.end();++it)
            {
                if(it->m_variable == word)
                {
                    val1 = std::stoi(it->m_value);
                    break;
                }
            }
            if(it == m_vec.end())
            {
                error(std::string("Use of undeclared identifier '") + word + "'");
            }
            line >> word;
            line >> word;
                        line >> word;

            if (word != "+" && word != "-")
            {
                error (std::string("Use of undeclared operator '") + word + "'");
            }
            if (word == "+")
            {
                line >> word;
                val1 += std::stoi (word);   
            }
            else
            {
                line >> word;
                val1 -= std::stoi (word);  
            }
            it->m_value = std::to_string(val1);
        }
    ++i;
    if (m_fileVec[i] != "]")
    {
        check_loop(i);
    }
}