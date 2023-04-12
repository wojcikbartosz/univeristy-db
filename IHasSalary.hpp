#ifndef I_HAS_SALATY_HPP
#define I_HAS_SALATY_HPP
#include <string>
class IHasSalary
{
    protected:
    std::string salary_;
    public:
    IHasSalary(std::string salary) : salary_(salary){}
    IHasSalary(){};
    virtual std::string getSalary()const = 0;
    virtual void setSalary(std::string) = 0;
};


#endif