#ifndef I_HAS_INDEX_NUMBER_HPP
#define I_HAS_INDEX_NUMBER_HPP
#include <string>
class IHasIndexNumber
{
    protected:
    std::string indexNumber_;
    public:
    IHasIndexNumber(std::string indexNumber) : indexNumber_(indexNumber){}
    IHasIndexNumber(){};
    virtual std::string getIndexNumber()const = 0;
    virtual void setIndexNumber(std::string) = 0;
};


#endif