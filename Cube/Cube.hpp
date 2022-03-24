#include "Cube.h"

Cube::Cube(std::string& str)
{
    
    oin.open(str);
    if (fin.is_open())
    {
        std::cout << "Error opening file\n";
    }
    else
    {
        code();
        change_string();
        cube_index_and_chenge();
        text_print();
    }
}

void Cube::readFile ()
{
    std::string line;
    while (std::getline(oin, line))
    {
        m_code_string = line;
    }
    oin.close();
}

void Cube::code()
{
    readFile();
}

void Cube::change_string()
{
    while(m_code_string.size() % m_cube_size != 0)
    {
        m_code_string.push_back(' ') ;
    }
    while(m_code_string.size() != 0)
    {
        m_vec_string.push_back(m_code_string.substr(0,m_cube_size));
        m_code_string.erase(0,m_cube_size);
    }
}

void Cube::cube_up(int index)
{
    std::string tmp;
    tmp.resize(m_vec_string[index].size(), ' ');
    tmp[0] = m_vec_string[index][3];
    tmp[1] = m_vec_string[index][2];
    tmp[2] = m_vec_string[index][6];
    tmp[3] = m_vec_string[index][7];
    tmp[4] = m_vec_string[index][0];
    tmp[5] = m_vec_string[index][1];
    tmp[6] = m_vec_string[index][5];
    tmp[7] = m_vec_string[index][4];
    m_vec_string[index] = tmp;            
}

void Cube::cube_down(int index)
{
    std::string tmp;
    tmp.resize(m_vec_string[index].size(), ' ');
    tmp[0] = m_vec_string[index][4];
    tmp[1] = m_vec_string[index][5];
    tmp[2] = m_vec_string[index][1];
    tmp[3] = m_vec_string[index][0];
    tmp[4] = m_vec_string[index][7];
    tmp[5] = m_vec_string[index][6];
    tmp[6] = m_vec_string[index][2];
    tmp[7] = m_vec_string[index][3];
    m_vec_string[index] = tmp;    
}

void Cube::cube_left(int index)
{
    std::string tmp;
    tmp.resize(m_vec_string[index].size(), ' ');
    tmp[0] = m_vec_string[index][1];
    tmp[1] = m_vec_string[index][2];
    tmp[2] = m_vec_string[index][3];
    tmp[3] = m_vec_string[index][0];
    tmp[4] = m_vec_string[index][5];
    tmp[5] = m_vec_string[index][6];
    tmp[6] = m_vec_string[index][7];
    tmp[7] = m_vec_string[index][4];
    m_vec_string[index] = tmp;    
}

void Cube::cube_right(int index)
{
    std::string tmp;
    tmp.resize(m_vec_string[index].size(), ' ');
    tmp[0] = m_vec_string[index][3];
    tmp[1] = m_vec_string[index][0];
    tmp[2] = m_vec_string[index][1];
    tmp[3] = m_vec_string[index][2];
    tmp[4] = m_vec_string[index][7];
    tmp[5] = m_vec_string[index][4];
    tmp[6] = m_vec_string[index][5];
    tmp[7] = m_vec_string[index][6];
    m_vec_string[index] = tmp;    
}

void Cube::cube_index_and_chenge ()
{
    std::string str;
    do
    {
        std::cout << "Please enter the cube index" << std::endl;
        int that_cube;
        while(true) 
        {
            std::cin >> that_cube;
            code_inform += std::to_string(that_cube);
            code_inform += ':';
            if(that_cube > m_vec_string.size()) 
            {
                std::cout << "There is no index cube you entered" << std::endl;
                continue;
            } 
            else 
            {
                break;
            }
        }
        char ch;
        std::cout << "Please enter the direction you want the cube to move:" << std::endl;
        std::cout << "1:Up - U" << std::endl;
        std::cout << "2:Down - D" << std::endl;
        std::cout << "3:Left - L" << std::endl;
        std::cout << "4:Right - R" << std::endl;
        std::cin >> ch;
        std::cin.get();
        code_inform.push_back(ch);
        code_inform.push_back(':');
        if (ch == 'U')
        {
            cube_up(that_cube);        
        }
        else if (ch == 'D')
        {
            cube_down(that_cube);        
        }
        else if (ch == 'L')
        {
            cube_left(that_cube);        
        }
        else if (ch == 'R')
        {
            cube_right(that_cube);
        }
        else
        {
            std::cout << "Incorrect entry Please enter again:" << std::endl;
            cube_index_and_chenge();
        }
        std::cout << "Do you want to rotate the cube again?" << std::endl;
        std::cout << "Yes or No" << std::endl;
        std::getline(std::cin,str);
    } while(str != "No");
    std::string str1;
    std::cout << "Do you want to decode?" << std::endl;
    std::cout << "Yes or No" << std::endl;
    while (true)
    {
        std::getline(std::cin,str1);
        if (str1 == "Yes" || str1 == "No")
        {
            break;
        }
        else
        {
            std::cout << "Wrong typing please type again:" << std::endl;
            continue;
        }
    }
    if (str1 == "Yes")
    {
        decode();
    }
    else
    {
        exit(0);  
    }
}

void Cube::decode()
{
    for (int i = 0; i < code_inform.size(); ++i)
    {
        int index = 0;
        if (code_inform[i] == 'U')
        {
            index = i - 2;
            cube_down(code_inform[index] - 48);
        }
        if (code_inform[i] == 'D')
        {
            index = i - 2;
            cube_up(code_inform[index] - 48);
        }
        if(code_inform[i] == 'L')
        {
            index = i - 2;
            cube_right(code_inform[index] - 48);
        }
        if (code_inform[i] == 'R')
        {
            index = i - 2;
            cube_left(code_inform[index] - 48);
        }
    }
}

void Cube::text_print()
{
    fin;
    fin.open ("deCode.txt");
    for (int i = 0; i < m_vec_string.size(); ++i)
    {
        fin <<  m_vec_string[i];
    }
    fin << "\n";
    code_inform.pop_back();
    for (int j = 0; j < code_inform.size(); ++j)
    {
        fin << code_inform[j];
    }
}

