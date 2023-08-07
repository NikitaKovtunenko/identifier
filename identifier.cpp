#include "identifier.h"
#include <iostream>


Identifier::Identifier()
:_value{IdentifierGroup("A1")}
{}


Identifier::Identifier(const std::string& id)
{
    int beginPos = 0;
    int endPos = id.find(_separator, beginPos);

    while (std::string::npos != endPos)
    {
        _value.push_back(IdentifierGroup(id.substr(beginPos, endPos - beginPos)));
        beginPos = endPos + 1;
        endPos = id.find(_separator, beginPos);
    }

    _value.push_back(IdentifierGroup(id.substr(beginPos)));

    if (_value.size() > _maxCount)
    {
        std::cout << "The maximum ID length has been exceeded!" << std::endl;
        throw  "The maximum ID length has been exceeded";
    }
}
Identifier::Identifier(const Identifier& id)
{
    _value = id._value;
}

Identifier::Identifier(Identifier&& id)
{
    _value = std::move(id._value);
}

std::string Identifier::data()
{
    std::string result;

    for (auto& str : _value)
    {
        result += str.getValue() + _separator;
    }

    result.pop_back();
    return result;
}

std::string Identifier::getValue()
{
    std::lock_guard<std::mutex> lock(_mtx);
    return data();
}

void Identifier::increment()
{
   auto it = _value.rbegin();
   
   while(it != _value.rend())
   {
    ++(*it);
    if(it->getValue() != "A1")
    break;

    ++it;
   }

   if(it == _value.rend())
   {
    if(_value.front().getValue() == "A1")
        _value.push_back(IdentifierGroup("A1"));

   }

   if(_value.size() > _maxCount)
   {
    std::cout<<"Max size"<<std::endl;
    throw "Max size";
   }
    
}

std::string Identifier::operator++()
{
    std::lock_guard<std::mutex> lock(_mtx);
   
    this->increment();
    return this->data();
}

std::string Identifier::operator++(int)
{
    std::lock_guard<std::mutex> lock(_mtx);
    std::string copy = this->data();
    this->increment();
    return copy;
}

Identifier& Identifier::operator = (const Identifier& id)
{
    std::lock_guard<std::mutex> lock(_mtx);
    if (this != &id)
    {
        _value = id._value;
    }

    return *this;
}

Identifier& Identifier::operator = (Identifier&& id)
{
    std::lock_guard<std::mutex> lock(_mtx);
    if (this != &id)
    {
        _value = std::move(id._value);
    }

    return *this;
}

void Identifier::setValue(const std::string& id)
{
    std::lock_guard<std::mutex> lock(_mtx);
    std::list<IdentifierGroup> value;
    int beginPos = 0;
    int endPos = id.find(_separator, beginPos);

    while (std::string::npos != endPos)
    {
        value.push_back(IdentifierGroup(id.substr(beginPos, endPos - beginPos)));
        beginPos = endPos + 1;
        endPos = id.find(_separator, beginPos);
    }

    value.push_back(IdentifierGroup(id.substr(beginPos)));

    if (value.size() > _maxCount)
    {
        std::cout << "The maximum ID length has been exceeded!" << std::endl;
        throw  "The maximum ID length has been exceeded";
    }

    _value = std::move(value);

     
}