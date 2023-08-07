

#include "identifiergroup.h"
#include <iostream>


IdentifierGroup::IdentifierGroup(const std::string& id)
:_id(id)
{
    if(_id.length() > 2)
    {
        std::cout<<"Invalid lenth";

        throw "Invalid lenght";
    }

    if(!checkLatter(_id[0]))
    {
        std::cout<<"Invalid latter";

        throw "Invalid latter";
    }    

    if(!checkNumber(_id[1]))
    {
        std::cout<<"Invalid number";
        throw "Invalid number";
    }

 
}

bool IdentifierGroup::checkLatter(const char& ch)
{
    return 'A' <= ch &&
           'Z' >= ch &&
           'D' != ch &&
           'F' != ch &&
           'G' != ch &&
           'J' != ch &&
           'M' != ch &&
           'Q' != ch &&
           'V' != ch;
}

bool IdentifierGroup::checkNumber(const char& num)
{
    return num > '0' && num < '10';
}

bool IdentifierGroup::incrementNum()
{
    char num = _id[1];

    ++num;

    if(num > '9')
    {
        _id[1] = '1';
        return true;
    }
    
    _id[1] = num;

    return false;

}


void IdentifierGroup::incrementLatter()
{
    char ch = _id[0];

    ++ch;

    while (!checkLatter(ch))
    {
        ++ch;

    }

    if(ch > 'Z')
    {
        _id[0]  = 'A';
        return;
    }

    _id[0] = ch;

}


std::string IdentifierGroup::operator++()
{
    
    if(incrementNum())
    {
        incrementLatter();
    }

    return _id;

}

const std::string&  IdentifierGroup::getValue()
{
    return _id;
}




const IdentifierGroup& IdentifierGroup::operator= (const IdentifierGroup& gp)
{
    if (this != &gp)
    {

        _id = gp._id;

    }

    return *this;
}

void IdentifierGroup::setId(const std::string& str)
{
    if (str.length() > 2)
    {
        std::cout << "Invalid lenth";

        throw "Invalid lenght";
    }

    if (!checkLatter(str[0]))
    {
        std::cout << "Invalid latter";

        throw "Invalid latter";
    }

    if (!checkNumber(str[1]))
    {
        std::cout << "Invalid number";
        throw "Invalid number";
    }

    _id = str;
}

