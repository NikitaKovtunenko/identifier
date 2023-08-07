#ifndef IDENTIFIER_H_INCLUDED
#define IDENTIFIER_H_INCLUDED

#include <mutex>
#include "identifiergroup.h"

class Identifier
{
    private:
    std::mutex _mtx;
    std::list<IdentifierGroup> _value ;
    static const int _maxCount = 10;
    static const char _separator = '-';
    void increment();
    std::string data();

    
    public:
    Identifier();
    Identifier(const std::string& id);
    Identifier(const Identifier& id);
    Identifier(Identifier&& id);
    std::string getValue();
    Identifier& operator = (const Identifier& id);
    Identifier& operator = (Identifier&& id);
    std::string operator++();
    std::string operator++(int);
    void setValue(const std::string&);


};

#endif //IDENTIFIER_H_INCLUDED

