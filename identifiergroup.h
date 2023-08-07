#ifndef IDENTIFIERGROUP_H_INCLUDED
#define IDENTIFIERGROUP_H_INCLUDED
#include <list>
#include <string>

class IdentifierGroup
{
    std::string _id;
    static bool checkLatter(const char& ch);
    static bool checkNumber(const char& num);
    bool incrementNum();
    void incrementLatter();

 public:
    IdentifierGroup(const   std::string& id);
    std::string   operator++();
    const std::string&   getValue();
    const IdentifierGroup& operator= (const IdentifierGroup& gp);
    void setId(const std::string& str);


};

#endif //IDENTIFIERGROUP_H_INCLUDED